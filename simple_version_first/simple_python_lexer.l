%{
#include "simple_python_parser.tab.h"
int indentation_level = 0;
%}

%%
\n              { indentation_level = 0; return NEWLINE; }
[ \t\f\r\v]+    { 
    int level = strlen(yytext);
    if (level < indentation_level) {
        yylval.dedent = indentation_level - level;
        indentation_level = level;
        return DEDENT;
    } else if (level > indentation_level) {
        yylval.indent = level - indentation_level;
        indentation_level = level;
        return INDENT;
    } else {
        return WHITESPACE;
    }
}

"="                 { return EQ; }
";"                 { return SEMICOLON; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return ID; }
[0-9]+                 { yylval.int_val = atoi(yytext); return INT; }
[0-9]+(\.[0-9]+)?      { yylval.float_val = atof(yytext); return FLOAT; }
.                   { /* ignore unrecognized characters */ }
%%

int yywrap() {
    return 1;
}
