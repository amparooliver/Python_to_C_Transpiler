%{
#include "parser.tab.h"
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
#.*\n           { return COMMENT;}
"if"            { return IF; }
"else"          { return ELSE; }
"for"           { return FOR; }
"in"            { return IN; }
"range"         { return RANGE; }
":"             { return COLON; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
","             { return COMMA; }
"="             { return EQ; }
"<"             { return LT; }      
">"             { return GT; }      
"<="            { return LTEQ; }     
">="            { return GTEQ; }
"+"             { return PLUS; }     // Added for +
"-"             { return MINUS; }    // Added for -
"*"             { return TIMES; }    // Added for *
"/"             { return DIVIDE; }   // Added for /    
[a-zA-Z_][a-zA-Z_0-9]* { yylval.str_val = strdup(yytext); return ID; }
[0-9]+                 { yylval.int_val = atoi(yytext); return INT; }
[0-9]+(\.[0-9]+)?      { yylval.float_val = atof(yytext); return FLOAT; }
\"[^\"]*\"             { yylval.str_val = strdup(yytext); return STRING; }



%%

int yywrap() {
    return 1;
}