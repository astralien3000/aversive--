%{

#include "y.tab.h"
#include <iostream>

#include <identifier.hpp>

#include <uc_node.hpp>
#include <hardware_node.hpp>
#include <register_node.hpp>
#include <struct_node.hpp>
#include <config_node.hpp>
#include <cstring>

  int yylex(void);

  ParentNode* root = 0;
  std::list<ParentNode*> context;

  RegisterNode* cur_register = 0;

  indented_stream out(std::cout);

  int yyerror(const char* s);
%}

%union {
  char id[1024];
  int n;
  void* data; // WARNING
}

%token <id>IDENTIFIER_TOKEN
%token <n>NUMERIC_TOKEN

%token UC_TOKEN
%token HARDWARE_TOKEN
%token REGISTER_TOKEN
%token CONFIG_TOKEN
%token CONFIG_LIST_TOKEN

%token SEP_BLOCK_TOKEN

%token BEG_LIST_TOKEN
%token END_LIST_TOKEN
%token SEP_LIST_TOKEN

%token ASSIGN_TOKEN

%type <n>REGISTER_SIZE
%type <data>ID_CASE

%type <id>VAL
%type <id>T
%type <id>F
%type <id>EXPR


%%

 ////////////////////////////////////////
 // UC

UC
: UC_DECL SEP_BLOCK
| UC_DECL UC_BLOCK SEP_BLOCK
;

UC_DECL
: UC_TOKEN IDENTIFIER_TOKEN {
  if(!root) {
    root = new UcNode(std::string($2));
    context.push_front(root);
  }
  else {
    std::cerr << "ERROR : There is already a uc !?" << std::endl;
  }
 }
;

UC_BLOCK
: BEG_LIST_TOKEN HARDWARE_LIST END_LIST_TOKEN
;

 ////////////////////////////////////////
 // HARDWARE

HARDWARE_LIST
: HARDWARE
| HARDWARE HARDWARE_LIST
;

HARDWARE
: HARDWARE_DECL SEP_BLOCK
| HARDWARE_DECL HARDWARE_BLOCK SEP_BLOCK
;

HARDWARE_DECL
: HARDWARE_TOKEN ID_CASE {
  if(context.front()) {
    HardwareNode* nod = new HardwareNode(*(Identifier*)$2);
    nod->setParent(context.front());
    context.push_front(nod);
  }
  else {
    std::cerr << "ERROR" << std::endl;
  }
 }
;

HARDWARE_BLOCK
: BEG_LIST_TOKEN REGISTER_LIST END_LIST_TOKEN
;

 ////////////////////////////////////////
 // REGISTER

REGISTER_LIST
: REGISTER
| REGISTER REGISTER_LIST
;

REGISTER
: REGISTER_DEF SEP_BLOCK
| REGISTER_DEF REGISTER_BLOCK SEP_BLOCK
;

REGISTER_DEF
: REGISTER_DECL ASSIGN_TOKEN REG_EXPR
;

REGISTER_DECL
: REGISTER_SIZE ID_CASE {
  if(context.front()) {
    RegisterNode* nod = new RegisterNode(*(Identifier*)$2, $1);
    nod->setParent(context.front());
    context.push_front(nod);
  }
 }
;

REGISTER_BLOCK
: BEG_LIST_TOKEN CONFIG_LIST END_LIST_TOKEN
;

REGISTER_SIZE
: REGISTER_TOKEN '[' NUMERIC_TOKEN ']' {
  $$ = $3;
 }
;

REG_EXPR
: BEG_LIST_TOKEN REG_LIST END_LIST_TOKEN
;

REG_LIST
: IDENTIFIER_TOKEN {
  RegisterNode& reg = *dynamic_cast<RegisterNode*>(context.front());
  reg.regs().push_front($1);
 }
| IDENTIFIER_TOKEN SEP_LIST_TOKEN REG_LIST {
  RegisterNode& reg = *dynamic_cast<RegisterNode*>(context.front());
  reg.regs().push_front($1);
 }
;

 ////////////////////////////////////////
 // CONFIG_TREE

CONFIG_LIST
: CONFIG
| CONFIG CONFIG_LIST
;

CONFIG
: C
| CL
;

 ////////////////////////////////////////
 // CONFIG

C
: C_DEF SEP_BLOCK
;

C_DEF
: C_DECL ASSIGN_TOKEN CONF_EXPR
;

C_DECL
: CONFIG_TOKEN ID_CASE {
  if(context.front()) {
    ConfigNode* nod = new ConfigNode(*(Identifier*)$2);
    nod->setParent(context.front());
    context.push_front(nod);
  }
 }
;

CONF_EXPR
: BEG_LIST_TOKEN CONF_LIST END_LIST_TOKEN
;

CONF_LIST
: EXPR {
  ConfigNode& nod = *dynamic_cast<ConfigNode*>(context.front());
  nod.confs().push_front($1);
 }
| EXPR SEP_LIST_TOKEN CONF_LIST {
  ConfigNode& nod = *dynamic_cast<ConfigNode*>(context.front());
  nod.confs().push_front($1);
 }
;

 ////////////////////////////////////////
 // CONFIG_LIST

CL
: CL_DECL CL_BLOCK SEP_BLOCK
;

CL_DECL
: CONFIG_LIST_TOKEN ID_CASE {
  if(context.front()) {
    StructNode* nod = new SubRegisterNode(*(Identifier*)$2);
    nod->setParent(context.front());
    context.push_front(nod);
  }
 }
;

CL_BLOCK
: BEG_LIST_TOKEN CONFIG_LIST END_LIST_TOKEN
;

 ////////////////////////////////////////
 // EXPR

EXPR
: F {
  strcpy($$, $1);
 }
| F '|' EXPR {
  sprintf($$, "%s | %s", $1, $3);
 }
;

F
: T {
  strcpy($$, $1);
 }
| T '&' F {
  sprintf($$, "%s & %s", $1, $3);
 }
;

T
: VAL {
  strcpy($$, $1);
 }
| '(' VAL '<' VAL ')' {
  sprintf($$, "(%s << %s)", $2, $4);
 }
| '(' VAL '>' VAL ')' {
  sprintf($$, "(%s >> %s)", $2, $4);
 }
| '~' VAL {
  sprintf($$, "~%s", $2);
 }
| '(' EXPR ')' {
  sprintf($$, "(%s)", $2);
 }
;

VAL
: IDENTIFIER_TOKEN {
  strcpy($$, $1);
 }
| NUMERIC_TOKEN {
  sprintf($$, "%d", $1);
  }
;

 ////////////////////////////////////////
 // ID_CASE

ID_CASE
: IDENTIFIER_TOKEN {
  $$ = new Identifier(std::string($1));
 }
| IDENTIFIER_TOKEN '[' NUMERIC_TOKEN ']' {
  $$ = new Identifier(std::string($1), $3);
 }
| NUMERIC_TOKEN {
  $$ = new Identifier($1);
 }
;

SEP_BLOCK
: SEP_BLOCK_TOKEN {
  context.pop_front();
 }
;

%%

int yyerror(const char* s) {
  std::cerr << "ERROR!" << std::endl;
  return -1;
}

int main (int argc, char *argv[]) {

  context.push_front(0);

  yyparse ();

  if(!root) {
    std::cerr << "ERROR : Could'nt parse document, no uc found" << std::endl;
  }

  root->declare(out);
  root->define(out);
  root->defineValue(out);

  return 0;
}
