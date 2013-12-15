%{
#include "y.tab.h"

%}

%%

uc { return UC_TOKEN; }
hardware { return HARDWARE_TOKEN; }

template { return TEMPLATE_TOKEN; }

register8 { yylval.n = 8; return REGISTER_TOKEN; }
register16 { yylval.n = 16; return REGISTER_TOKEN; }
register32 { yylval.n = 32; return REGISTER_TOKEN; }
register64 { yylval.n = 64; return REGISTER_TOKEN; }

config-list { return CONFIG_LIST_TOKEN; }
config { return CONFIG_TOKEN; }

[a-zA-Z_][a-zA-Z0-9_]* { strcpy(yylval.id, yytext); return ID; }
[0-9]* { yylval.n = atoi(yytext); return N; }

\~ { return '~'; }
\| { return '|'; }
\& { return '&'; }

\<\< { return '<'; }
\>\> { return '>'; }

\( { return '('; }
\) { return ')'; }

\[ { return '['; }
\] { return ']'; }

, { return ','; }

\ \ \ \  {}
\t {}

\  {}
\n {}
. { return -1; }

%%