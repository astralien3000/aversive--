%{

#include "y.tab.h"

%}

%%

uc {
  return UC_TOKEN;
}

hardware {
  return HARDWARE_TOKEN;
}

template {
  return TEMPLATE_TOKEN;
}

register {
  return REGISTER_TOKEN;
}

config-list {
  return CONFIG_LIST_TOKEN;
}

config {
  return CONFIG_TOKEN;
}

[a-zA-Z_][a-zA-Z0-9_]* {
  strcpy(yylval.id, yytext);
  return IDENTIFIER_TOKEN;
}

[0-9]* {
  yylval.n = atoi(yytext);
  return NUMERIC_TOKEN;
}

\{ {
  return BEG_LIST_TOKEN;
}

\} {
  return END_LIST_TOKEN;
}

\, {
  return SEP_LIST_TOKEN;
}

\; {
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
