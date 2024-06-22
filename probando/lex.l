%{
#include "parser.tab.h"
int indentation_level = 0;
%}

%%
\n                        { indentation_level = 0; return NEWLINE; }
^[ \t\f\r\v]+                   { int level = strlen(yytext); 
                          fprintf(stderr, "detecta indent en lex?, valor de level %d \n ",level);
                          if( level < indentation_level){
                            yylval.indent = indentation_level - level;
                            indentation_level = level;
                            return DEDENT;
                          }else if (level > indentation_level){
                            yylval.dedent = level;
                            indentation_level = level;
                            return INDENT;
                          } else {
                            return WHITESPACE;
                          } 
                        }
"="                     { return EQ; }
"if"                    { return IF; }
":"                     { return COLON;}
"<"                     { return LT; }  
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return ID; }
[0-9]+                  { yylval.int_val = atoi(yytext); return INT; }
[0-9]+(\.[0-9]+)?       { yylval.float_val = atof(yytext); return FLOAT; }
(\"[A-Za-z]\")          { yylval.str = strdup(yytext); return CHAR; }
(\"[^\"]+\")            { yylval.str = strdup(yytext); return STRING; }

%%

int yywrap() {
    return 1;
}
