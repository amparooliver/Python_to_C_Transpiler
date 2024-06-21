%{
#include "parser.tab.h"
#include <string.h>

extern int yylineno;
extern char* yytext;

void yyerror(char* s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
    exit(1);
}

%}

WS      [ \t\r]
COMMENT #.*
NEWLINE \n
INDENT  [ \t]+
DEDENT  [ \t]-
ID      [a-zA-Z_][a-zA-Z_0-9]*
INT     [0-9]+
FLOAT   [0-9]+(\.[0-9]+)?
STRING  \"[^\"]*\"
LPAREN  \( 
RPAREN  \)
LBRACE  \{
RBRACE  \}
COMMA ,
COLON   :
EQ      =
IN      in
RANGE   range
IF      if
ELSE    else
FOR     for

%%

{WS}    { /* ignore whitespace */ }
{COMMENT} { /* ignore comments */ }
{NEWLINE} { yylineno++; }
{INDENT} { yylval.indent = strlen(yytext); return INDENT; }
{DEDENT} { yylval.dedent = strlen(yytext); return DEDENT; }
{ID}     { yylval.id = strdup(yytext); return ID; }
{INT}    { yylval.int_val = atoi(yytext); return INT; }
{FLOAT}  { yylval.float_val = atof(yytext); return FLOAT; }
{STRING} { yylval.string_val = strdup(yytext); return STRING; }
{LPAREN} { return LPAREN; }
{RPAREN} { return RPAREN; }
{LBRACE} { return LBRACE; }
{RBRACE} { return RBRACE; }
{COMMA}  { return COMMA; }
{COLON}  { return COLON; }
{EQ}     { return EQ; }
{IN}     { return IN; }
{RANGE}  { return RANGE; }
{IF}     { return IF; }
{ELSE}   { return ELSE; }
{FOR}    { return FOR; }

.       { yyerror("Invalid character"); }

%%

int yywrap() {
    return 1;
}