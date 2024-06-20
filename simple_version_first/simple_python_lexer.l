%{
#include "simple_python_parser.tab.h"
%}

%%
"int"               { return INT; }
"float"             { return FLOAT; }
"="                 { return ASSIGN; }
";"                 { return SEMICOLON; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENTIFIER; }
[0-9]+              { yylval.num = atoi(yytext); return NUMBER; }
[ \t\n\r]+          { /* ignore whitespace */ }
.                   { /* ignore unrecognized characters */ }
%%

int yywrap() {
    return 1;
}
