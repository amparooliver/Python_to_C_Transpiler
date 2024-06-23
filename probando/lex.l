%{
#include "parser.tab.h"
int indentation_level = 0;
%}

%%
\n                        { //indentation_level = 0; 
                          fprintf(stderr, " NEWLINE DETECTADA\n");
                          return NEWLINE; }

^[ \t\f\r\v]+             { int level = strlen(yytext); 
                           fprintf(stderr, "espacio detectado, nivel en: %d \n ",level);
                            fprintf(stderr, "indentation_level= %d \n ", indentation_level);
                            fprintf( stderr,"if( level %d < indentation_level %d) \n ", level, indentation_level);
                          if( level < indentation_level){
                            yylval.dedent = indentation_level - level;
                            indentation_level = level;
                            fprintf(stderr, "retorna DEDENT \n ");
                            return DEDENT;
                          }else if (level > indentation_level){
                            yylval.indent = level;
                            indentation_level = level;
                            fprintf(stderr, "retorna INDENT \n ");
                            return INDENT;
                          } else {
                            fprintf(stderr, "No hago nada misma indentacion \n ");
                            //return WHITESPACE;
                          } 
                        }
"="                     { return EQ; }
"if"                    { return IF; }
":"                     { fprintf(stderr, "retorna COLON \n "); return COLON;}
"<"                     { return LT; }  
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return ID; }
[0-9]+                  { yylval.int_val = atoi(yytext); return INT; }
[0-9]+(\.[0-9]+)?       { yylval.float_val = atof(yytext); return FLOAT; }
(\"[A-Za-z]\")          { yylval.str = strdup(yytext); return CHAR; }
(\"[^\"]+\")            { yylval.str = strdup(yytext); return STRING; }
<<EOF>>                 { 
                          fprintf(stderr, "Fin de archivo detectado\n");
                          return 0; // O un token especial como END_OF_FILE
                         }
%%

int yywrap() {
    return 1;
}
