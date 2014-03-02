%{

#include "y.tab.h"

#include <iostream>

%}

%%

uc {
  std::cerr << "uc" << std::endl;
  return UC_TOKEN;
}

hardware {
  std::cerr << "hardware" << std::endl;
  return HARDWARE_TOKEN;
}

register {
  std::cerr << "register" << std::endl;
  return REGISTER_TOKEN;
}

config-list {
  std::cerr << "config-list" << std::endl;
  return CONFIG_LIST_TOKEN;
}

config {
  std::cerr << "config" << std::endl;
  return CONFIG_TOKEN;
}

[a-zA-Z_][a-zA-Z0-9_]* {
  std::cerr << "identifier : " << yytext << std::endl;
  strcpy(yylval.id, yytext);
  return IDENTIFIER_TOKEN;
}

[0-9]* {
  std::cerr << "numeric : " << yytext << std::endl;
  yylval.n = atoi(yytext);
  return NUMERIC_TOKEN;
}

= {
  std::cerr << "assignment" << std::endl;
  return ASSIGN_TOKEN;
}

\{ {
  std::cerr << "block begin" << std::endl;
  return BEG_LIST_TOKEN;
}

\} {
  std::cerr << "block end" << std::endl;
  return END_LIST_TOKEN;
}

\, {
  std::cerr << "list separator" << std::endl;
  return SEP_LIST_TOKEN;
}

\; {
  std::cerr << "block separator" << std::endl;
  return SEP_BLOCK_TOKEN;
}


\~ {
  return '~';
}

\| {
  return '|';
}

\& {
  return '&';
}

\<\< {
  return '<';
}

\>\> {
  return '>';
}

\( {
  return '(';
}

\) {
  return ')';
}

\[ {
  return '[';
}

\] {
  return ']';
}

. {
  // NOTHING
}

%%
