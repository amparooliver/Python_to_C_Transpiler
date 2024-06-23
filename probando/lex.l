%{

/* Trabajo Practico de Amparo Oliver - Compiladores

Basado en la documentacion: https://docs.python.org/3/reference/lexical_analysis.html#

Python Keywords:
False      await      else       import     pass
None       break      except     in         raise
True       class      finally    is         return
and        continue   for        lambda     try
as         def        from       nonlocal   while
assert     del        global     not        with
async      elif       if         or         yield

*/

#include "parser.tab.h"
int indentation_level = 0;
int bandera = 0;




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
                            bandera = level;
                            return INDENT;
                          } else {
                            fprintf(stderr, "No hago nada misma indentacion \n ");
                            //return WHITESPACE;
                          } 
                        }

"False"   { return FALSE; }
"None"    { return NONE; }
"True"    { return TRUE; }
"and"     { return AND; }
"as"      { return AS; }
"assert"  { return ASSERT; }
"async"   { return ASYNC; }
"wait"    { return WAIT; }
"break"   { return BREAK; }
"class"   { return CLASS; }
"continue"  { return CONTINUE; }
"def"       { return DEF; }
"del"       { return DEL; }
"elif"      { return ELIF; }
"else"      { return ELSE; }
"except"    { return EXCEPT; }
"finally"   { return FINALLY; }
"for"       { return FOR; }
"from"      { return FROM; }
"global"    { return GLOBAL; }
"if"        { return IF; }
"import"    { return IMPORT; }
"in"        { return IN; }
"is"        { return IS; }
"lambda"    { return LAMBDA; }
"nonlocal"  { return NONLOCAL; }
"not"       { return NOT; }
"or"        { return OR; }
"pass"      { return PASS; }
"raise"     { return RAISE; }
"return"    { return RETURN; }
"try"       { return TRY; }
"while"     { return WHILE; }
"with"      { return WITH; }
"yield"     { return YIELD; }


"="                     { return EQ; }
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
