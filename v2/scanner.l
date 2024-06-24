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

Python Operators:
+       -       *       **      /       //      %      @
<<      >>      &       |       ^       ~       :=
<       >       <=      >=      ==      !=

*/

%{
#include <iostream>
#include <stack>
#include <cstdlib>
#include <string.h>
#include "parser.hpp"
YYSTYPE yylval;
YYLTYPE yylloc;

yypstate* pstate = yypstate_new();

#define PUSH_TOKEN(token) do {  \
  int s = yypush_parse(pstate, token, &yylval, &yylloc);  \
  if (s != YYPUSH_MORE) {                                 \
    yypstate_delete(pstate);                              \
    return s;                                             \
  }                                                       \
} while(0)


std::stack<int> _indent_stack;
%}

%option noyywrap

%option yylineno

%%

%{
  /**/
  if (_indent_stack.empty()) {
    _indent_stack.push(0);
  }
%}

^[ \t]*\r?\n   { /* Ignoramos lineas en blanco */ }
^[ \t]*#.*\r?\n    { /* Ignoramos comentarios en una linea fisica */ }
#.*$        { /* Ignoramos comentarios que estan dps de un statement */ }

^[ \t]+     {
              /**/
              if (_indent_stack.top() < yyleng) {
                /**/
                //std::cout << "INDENT" << std::endl;
                _indent_stack.push(yyleng);
                PUSH_TOKEN((yylval.token = INDENT));
              } else {
                /**/
                while (!_indent_stack.empty() && _indent_stack.top() != yyleng) {
                  _indent_stack.pop();
                  //std::cout << "DEDENT" << std::endl;
                  PUSH_TOKEN((yylval.token = DEDENT));
                }

                /**/
                if (_indent_stack.empty()) {
                  std::cerr << "Error: Incorrect indentation on line "
                    << yylineno << std::endl;
                  return 1;
                  exit(1);
                }
              }
            }

^[^ \t\n]+  {
              /**/
              while(_indent_stack.top() != 0) {
                _indent_stack.pop();
                //std::cout << "DEDENT" << std::endl;
                PUSH_TOKEN((yylval.token = DEDENT));
              }
              REJECT;
            }

\r?\n       {
                PUSH_TOKEN((yylval.token = NEWLINE)); 
                //std::cout << "NEWLINE" << std::endl;
            }

<<EOF>>     {
              /**/
              while(_indent_stack.top() != 0) {
                _indent_stack.pop();
                //std::cout << "DEDENT" << std::endl;
                PUSH_TOKEN((yylval.token = DEDENT));
              }

              int s = yypush_parse(pstate, 0, NULL, NULL);
                yypstate_delete(pstate);
                return s;
              //yyterminate();
            }

[ \t]       { /* Ignoramos espacios blancos que no sean los de arriba */ }

"and"       {  PUSH_TOKEN((yylval.token = AND));
            //std::cout << "AND\t\t" << yytext << std::endl; 
            }

"break"     { PUSH_TOKEN((yylval.token = BREAK));
              //std::cout << "BREAK\t\t" << yytext << std::endl;
               }

"def"       { PUSH_TOKEN((yylval.token = DEF));
              //std::cout << "DEF\t\t" << yytext << std::endl;
               }

"elif"      { PUSH_TOKEN((yylval.token = ELIF));
              //std::cout << "ELIF\t\t" << yytext << std::endl;
               }

"else"      { PUSH_TOKEN((yylval.token = ELSE));
              //std::cout << "ELSE\t\t" << yytext << std::endl;
               }

"for"       { PUSH_TOKEN((yylval.token = FOR));
              //std::cout << "FOR\t\t" << yytext << std::endl;
               }

"if"        { PUSH_TOKEN((yylval.token = IF));
              //std::cout << "IF\t\t" << yytext << std::endl;
               }

"not"       { PUSH_TOKEN((yylval.token = NOT));
              //std::cout << "NOT\t\t" << yytext << std::endl;
               }

"or"        { PUSH_TOKEN((yylval.token = OR));
              //std::cout << "OR\t\t" << yytext << std::endl;
               }

"return"    { PUSH_TOKEN((yylval.token = RETURN));
              //std::cout << "RETURN\t\t" << yytext << std::endl;
               }

"while"     { PUSH_TOKEN((yylval.token = WHILE));
              //std::cout << "WHILE\t\t" << yytext << std::endl;
               }

"True"      { 
             yylval.str = new std::string("true", yyleng);
              PUSH_TOKEN(BOOLEAN);
              //std::cout << "BOOLEAN\t\t" << true << std::endl;
               }

"False"     { 
              yylval.str = new std::string("false", yyleng);
              PUSH_TOKEN(BOOLEAN);
              //std::cout << "BOOLEAN\t\t" << false << std::endl;
               }

[a-zA-Z_][a-zA-Z0-9_]*  {
                yylval.str = new std::string(yytext, yyleng);
                PUSH_TOKEN(IDENTIFIER);
                //std::cout << "IDENTIFIER\t\t" << yytext << std::endl; 
              }

-?[0-9]*"."[0-9]+   {
                     yylval.str = new std::string(yytext, yyleng);
                     PUSH_TOKEN(FLOAT);
                   }

-?[0-9]+    {
                     yylval.str = new std::string(yytext, yyleng);
                     PUSH_TOKEN(INTEGER);
                   }

(\"[^\"]+\")  {
                     yylval.str = new std::string(yytext, yyleng);
                     PUSH_TOKEN(STRING);
                   }

"="         { PUSH_TOKEN((yylval.token = EQUALS));
            //std::cout << "ASSIGN\t\t" << yytext << std::endl;
              } 

"+"         { PUSH_TOKEN((yylval.token = PLUS)); 
            //std::cout << "PLUS\t\t" << yytext << std::endl;
            }

"-"         {  PUSH_TOKEN((yylval.token = MINUS));
            //std::cout << "MINUS\t\t" << yytext << std::endl; 
            }

"*"         {  PUSH_TOKEN((yylval.token = TIMES));
            //std::cout << "TIMES\t\t" << yytext << std::endl;
             }

"/"         {  PUSH_TOKEN((yylval.token = DIVIDEDBY));
            //std::cout << "DIVIDEDBY\t" << yytext << std::endl;
             }

"=="        { PUSH_TOKEN((yylval.token = EQ));
            //std::cout << "EQ\t\t" << yytext << std::endl;
             }

"!="        { PUSH_TOKEN((yylval.token = NEQ));
            //std::cout << "NEQ\t\t" << yytext << std::endl;
             }

">"         { 
            PUSH_TOKEN((yylval.token = GT));
            //std::cout << "GT\t\t" << yytext << std::endl;
             }

">="        { PUSH_TOKEN((yylval.token = GTE));
            //std::cout << "GTE\t\t" << yytext << std::endl;
             }

"<"         { PUSH_TOKEN((yylval.token = LT));
            //std::cout << "LT\t\t" << yytext << std::endl;
             }

"<="        { PUSH_TOKEN((yylval.token = LTE));
            //std::cout << "LTE\t\t" << yytext << std::endl;
             }

"("         { PUSH_TOKEN((yylval.token = LPAREN));
            //std::cout << "LPAREN\t\t" << yytext << std::endl;
             }

")"         { PUSH_TOKEN((yylval.token = RPAREN));
            //std::cout << "RPAREN\t\t" << yytext << std::endl;
             }

","         {  PUSH_TOKEN((yylval.token = COMMA));
            //std::cout << "COMMA\t\t" << yytext << std::endl; 
            }

":"         { 
              PUSH_TOKEN((yylval.token = COLON));
              //std::cout << "COLON\t\t" << yytext << std::endl;
               }
"["         { 
              PUSH_TOKEN((yylval.token = LBRACK));
              //std::cout << "LBRACK\t\t" << yytext << std::endl;
               }
"]"         { 
              PUSH_TOKEN((yylval.token = RBRACK));
              //std::cout << "RBRACK\t\t" << yytext << std::endl;
               }

.           {
              std::cerr << "Simbolo no reconocido en la linea " << yylineno << " --> "
                << yytext << std::endl;
              return 1;
            }

%%
