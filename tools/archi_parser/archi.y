%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

#define STRUCT_MAX 1024

  void new_struct();
  void set_parent();
  void unset_parent();
  void clear_struct();

  void apply_num(char*, int, int);

  char struct_type[STRUCT_MAX][1024];
  char struct_def[STRUCT_MAX][1024];
  char struct_name[STRUCT_MAX][1024];
  char struct_code[STRUCT_MAX][1024];
  int struct_template[STRUCT_MAX];
  int struct_register[STRUCT_MAX];

  int s_config[STRUCT_MAX];
  int s_register[STRUCT_MAX];
  int s_rsize[STRUCT_MAX];

  char struct_parent[STRUCT_MAX];
  int parent = -1;

  int struct_id = -1;
 
%}

%union { char id[1024]; int n; }
%token <id>ID 
%token <n>N
%token TAB 
%token UC_TOKEN
%token TEMPLATE_TOKEN
%token HARDWARE_TOKEN
%token <n> REGISTER_TOKEN
%token CONFIG_TOKEN
%token CONFIG_LIST_TOKEN

%type <id> ID_CASE
%type <n> REG_EXPR

%type <id>T
%type <id>VAL 
%type <id>EXPR
%type <id>F

%%

SOURCE
: UC_TOKEN ID HARDWARE_LIST 
;

HARDWARE_LIST
: HARDWARE
| HARDWARE HARDWARE_LIST
;

HARDWARE
: HARDWARE_DECL  { unset_parent(); }
| HARDWARE_DECL REGISTER_LIST  { unset_parent(); }
;

HARDWARE_DECL
: HARDWARE_TOKEN ID_CASE  { 
  set_parent(); 
 }
;

REGISTER_LIST
: REGISTER
| REGISTER REGISTER_LIST
;

REGISTER
: REGISTER_DECL { 
  unset_parent(); 
 }
| REGISTER_DECL CONFIG_LIST { 
  unset_parent(); 
 }
;

REGISTER_DECL
: REGISTER_TOKEN ID_CASE REG_EXPR {
  struct_register[struct_id] = 1;
  s_rsize[struct_id] = $1;
  char buff[1024];
  sprintf(buff, "reg_size(%d), reg{%s}", $3, struct_code[struct_id]);
  sprintf(struct_code[struct_id], "%s", buff);
  apply_num(struct_code[struct_id], s_rsize[struct_id], $3);
  set_parent();
 }
;

REG_EXPR
: ID { 
  sprintf(struct_code[struct_id], "(u%%d*)&%s", $1);
  $$ = 1;
 }
| ID ',' REG_EXPR {
  char buff[1024];
  sprintf(buff, "%s, %s", $1, struct_code[struct_id]);
  sprintf(struct_code[struct_id], "(u%%d*)&%s", buff);
  $$ = 1 + $3;
  }
;

CONFIG_LIST
: CONFIG
| CONFIG CONFIG_LIST
;

CONFIG
: CONFIG_DECL
| CONFIG_CONFIG_LIST
;

CONFIG_DECL
: CONFIG_TOKEN ID_CASE CONF_EXPR {
  s_rsize[struct_id] = s_rsize[parent];
  char buff[1024];
  sprintf(buff, "conf{%s}", struct_code[struct_id]);
  strcpy(struct_code[struct_id], buff);
 }
;

CONFIG_CONFIG_LIST
: CONFIG_CONFIG_LIST_DECL SUB_CONFIG_LIST { unset_parent(); }
;

SUB_CONFIG_LIST
: SUB_CONFIG
| SUB_CONFIG SUB_CONFIG_LIST
;

SUB_CONFIG
: SUB_CONFIG_DECL
;

SUB_CONFIG_DECL
: CONFIG_DECL
;

CONFIG_CONFIG_LIST_DECL
: CONFIG_LIST_TOKEN ID_CASE { 
  s_rsize[struct_id] = s_rsize[parent];
  set_parent(); 
 }
;

CONF_EXPR
: EXPR {
  char buff[1024];
  sprintf(buff, "%s", $1);
  strcpy(struct_code[struct_id], buff);
 }
| EXPR ',' CONF_EXPR {
  char buff[1024];
  sprintf(buff, "%s, %s", $1, struct_code[struct_id]);
  strcpy(struct_code[struct_id], buff);
  }
;

EXPR
: F {
  sprintf($$, "%s", $1);
 }
| F '|' EXPR {
  sprintf($$, "%s | %s", $1, $3);
 }
;

F
: T {
  sprintf($$, "%s", $1);
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
  sprintf($$, "( %s << %s )", $2, $4);
 }
| '(' VAL '>' VAL ')' {
  sprintf($$, "( %s >> %s )", $2, $4);
 }
| '~' VAL {
  sprintf($$, "~%s", $2);
 }
| '(' EXPR ')' {
  sprintf($$, "(%s)", $2);
 }
;

VAL
: ID {
  strcpy($$, $1);
 }
| N {
  sprintf($$, "%d", $1);
  }
;

ID_CASE
: ID {
  new_struct();
  sprintf(struct_type[struct_id], "");
  sprintf(struct_def[struct_id], "struct %s;", $1);
  sprintf(struct_name[struct_id], "%s", $1);
  struct_template[struct_id] = 0;
  struct_register[struct_id] = 0;
 }
| ID '[' N ']' {
  new_struct();
  sprintf(struct_type[struct_id], "template<> ");
  sprintf(struct_def[struct_id], "template<int ID> struct %s;", $1);
  sprintf(struct_name[struct_id], "%s<%d>", $1, $3);
  struct_template[struct_id] = 1;
  struct_register[struct_id] = 0;
 }
| N {
  new_struct();
  sprintf(struct_type[struct_id], "template<> ");
  sprintf(struct_def[struct_id], "template<int ID> struct value;");
  sprintf(struct_name[struct_id], "value<%d>", $1);
  struct_template[struct_id] = 1;
  struct_register[struct_id] = 0;
  }
;

%%
int yyerror(char* s) { perror("ERROR!"); }


void new_struct() {
  struct_id++;
  struct_parent[struct_id] = parent;
}

void clear_struct() {
  struct_id--;
}

void set_parent() {
  parent = struct_id;
}

void unset_parent() {
  parent = struct_parent[parent];
}


void full_name(char* buff2, int id) {
  char buff[1024];
  sprintf(buff2, "%s", struct_name[id]);
  for(int j = struct_parent[id] ; j > -1 ; j = struct_parent[j]) {
    sprintf(buff, "%s::%s", struct_name[j], buff2);
    sprintf(buff2, "%s", buff);
  }
}

void full_type(char* buff2, int id) {
  char buff[1024];
  sprintf(buff2, "%s", struct_type[id]);
  for(int j = struct_parent[id] ; j > -1 ; j = struct_parent[j]) {
    sprintf(buff, "%s%s", struct_type[j], buff2);
    sprintf(buff2, "%s", buff);
  }
}

int nindent = 0;

void indent() {
  for(int i = 0 ; i < nindent ; i++) {
    printf("  ");
  }
}

int config = 0;

void new_config(int id) {
  indent();
  printf("enum { CONFIG = %d, SIZE = %d };\n", s_config[id] = config++, s_rsize[id]);
}

int reg = 0;

void new_register(int id) {
  indent();
  printf("enum { REG = %d, SIZE = %d };\n", s_register[id] = reg++, s_rsize[id]);
}

void declare(int id) {
  indent();
  printf("%s\n", struct_def[id]);
}

void sub_define(int id) {
  indent();
  printf("%sstruct %s {\n", struct_type[id], struct_name[id]);
  nindent++;
  int empty = 1;
  for(int i = 0 ; i < struct_id ; i++) {
    if(struct_parent[i] == id) {
      if(struct_template[i]) {
	declare(i);
      }
      else {
	sub_define(i);
      }
      empty = 0;
    }
  }
    
  if(struct_register[id] == 1) {
    new_register(id);
  }
  else {
    if(empty)
      new_config(id);
  }

  nindent--;
  indent();
  printf("};\n\n");
}

void define(int id) {
  char buff_name[1024], buff_type[1024];
  full_name(buff_name, id);
  full_type(buff_type, id);
  indent();
  printf("%sstruct %s {\n", buff_type, buff_name);
  nindent++;
  int empty = 1;
  for(int i = 0 ; i < struct_id ; i++) {
    if(struct_parent[i] == id) {
      if(struct_template[i]) {
	declare(i);
      }
      else {
	sub_define(i);
      }
      empty = 0;
    }
  }
  
  if(struct_register[id] == 1) {
    new_register(id);
  }
  else {
    if(empty)
      new_config(id);
  }

  nindent--;
  indent();
  printf("};\n\n");
}

void apply_num(char* str, int num, int n) {
  for(int i = 0 ; i < n ; i++) {
    char buff[1024];
    sprintf(buff, str, num, num, num, num);
    strcpy(str, buff);
  }
}


int main (int argc, char *argv[]) {

  yyparse ();

  for(int i = 0 ; i < struct_id ; i++) {
    if(struct_parent[i] == -1)
      declare(i);
    if(struct_template[i]) {
      define(i);
    }
  }

  for(int i = 0 ; i < struct_id ; i++) {
    if(struct_code[i][0] != 0) {
      if(struct_register[i] == 1) {
	printf("template<> inline Register<%d, %d>::Register(void) : %s {}\n", s_rsize[i], s_register[i], struct_code[i]);
      }
      else {
	printf("template<> inline Config<%d, %d>::Config(void) : %s {}\n", s_rsize[i], s_config[i], struct_code[i]);
      }
    }
  }

  return 0;
}
