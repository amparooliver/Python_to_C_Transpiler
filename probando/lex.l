%{
#include "parser.tab.h"
int indentation_level = 0;
%}

%%

"="                 { return EQ; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return ID; }
[0-9]+                 { yylval.int_val = atoi(yytext); return INT; }
[0-9]+(\.[0-9]+)?      { yylval.float_val = atof(yytext); return FLOAT; }
(\"[A-Za-z]\")         { yylval.str = strdup(yytext); return CHAR; }
(\"[^\"]+\")             { yylval.str = strdup(yytext); return STRING; }
%%

int yywrap() {
    return 1;
}
