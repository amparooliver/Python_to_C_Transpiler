%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
extern char* yytext;

void yyerror(char* s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
    exit(1);
}

FILE* output_file;


%}

%union {
    char* str_val;
    int int_val;
    float float_val;
    int dedent;   // Añadido para representar el nivel de dedentación
    int indent;   // Añadido para representar el nivel de indentación
    struct {
        char* code;
    } stmt;
    struct {
        char* code;
    } expr;
}

%token <str_val> ID STRING
%token <int_val> INT
%token <float_val> FLOAT
%token IF ELSE FOR IN RANGE COLON LPAREN RPAREN LBRACE RBRACE COMMA EQ
%token INDENT DEDENT NEWLINE WHITESPACE COMMENT
%token PLUS MINUS TIMES DIVIDE
%token LT GT LTEQ GTEQ

%type <stmt> program statement statements
%type <expr> expr

%%

program: 
        statements {
           fprintf(output_file, "#include <stdio.h>\n\n");
           fprintf(output_file, "int main() {\n");
           fprintf(output_file, "%s", $1.code);
           fprintf(output_file, "    return 0;\n");
           fprintf(output_file, "}\n");
       }
       ;

statements: 
        statement {
            $$ = malloc(sizeof(struct stmt));
            $$->stmt.code = strdup($1.code);
        }
        |
        statements statement 
        {
            $$ = malloc(sizeof(struct stmt));
            $$->stmt.code = malloc(strlen($1.code) + strlen($2.code) + 2);
            sprintf($$->code, "%s%s\n", $1.code, $2.code);
        }
        ;

statement: expr NEWLINE
        {
            $$ = malloc(sizeof(struct stmt));
            $$->stmt.code = malloc(strlen($1.code) + 10);
            sprintf($$->code, "    printf(\"%%d\\n\", %s);\n", $1.code);
        }
        | IF expr COLON NEWLINE INDENT statements DEDENT
        {
            $$ = malloc(sizeof(struct stmt));
            $$->stmt.code = malloc(strlen($2.code) + strlen($6.code) + 50);
            sprintf($$->code, "    if (%s) {\n%s    }\n", $2.code, $6.code);
        }
        | IF expr COLON NEWLINE INDENT statements DEDENT ELSE COLON NEWLINE INDENT statements DEDENT
        {
            $$ = malloc(sizeof(struct stmt));
            $$->stmt.code = malloc(strlen($2.code) + strlen($6.code) + strlen($12.code) + 70);
            sprintf($$->code, "    if (%s) {\n%s    } else {\n%s    }\n", $2.code, $6.code, $12.code);
        }
        | FOR ID IN RANGE LPAREN expr COMMA expr RPAREN COLON NEWLINE INDENT statements DEDENT
        {
            $$ = malloc(sizeof(struct stmt));
            $$->stmt.code = malloc(strlen($2) + strlen($6.code) + strlen($8.code) + strlen($13.code) + 70);
            sprintf($$->stmt.code, "    for (int %s = %s; %s <= %s; %s++) {\n%s    }\n", $2, $6.code, $2, $8.code, $2, $13.code);
        }
        ;

expr: INT
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code = malloc(20);
            sprintf($$->expr.code, "%d", $1);
        }
        | FLOAT
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code = malloc(20);
            sprintf($$->expr.code, "%f", $1);
        }
        | ID
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code= strdup($1);
        }
        | expr EQ expr
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code = malloc(strlen($1.code) + strlen($3.code) + 10);
            sprintf($$->expr.code, "%s == %s", $1.code, $3.code);
        }
        | expr EQ EQ expr
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code = malloc(strlen($1.code) + strlen($4.code) + 10);
            sprintf($$->expr.code, "%s == %s", $1.code, $4.code);
        }
        | expr LT expr
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code = malloc(strlen($1.code) + strlen($3.code) + 10);
            sprintf($$->expr.code, "%s < %s", $1.code, $3.code);
        }
        | expr GT expr
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code = malloc(strlen($1.code) + strlen($3.code) + 10);
            sprintf($$->expr.code, "%s > %s", $1.code, $3.code);
        }
        | expr LTEQ expr
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code = malloc(strlen($1.code) + strlen($3.code) + 10);
            sprintf($$->expr.code, "%s <= %s", $1.code, $3.code);
        }
        | expr GTEQ expr
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code = malloc(strlen($1.code) + strlen($3.code) + 10);
            sprintf($$->expr.code, "%s >= %s", $1.code, $3.code);
        }
        | expr PLUS expr
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code = malloc(strlen($1.code) + strlen($3.code) + 10);
            sprintf($$->expr.code, "%s + %s", $1.code, $3.code);
        }
        | expr MINUS expr
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code = malloc(strlen($1.code) + strlen($3.code) + 10);
            sprintf($$->expr.code, "%s - %s", $1.code, $3.code);
        }
        | expr TIMES expr
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code = malloc(strlen($1.code) + strlen($3.code) + 10);
            sprintf($$->expr.code, "%s * %s", $1.code, $3.code);
        }
        | expr DIVIDE expr
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code= malloc(strlen($1.code) + strlen($3.code) + 10);
            sprintf($$->expr.code, "%s / %s", $1.code, $3.code);
        }
        | LPAREN expr RPAREN
        {
            $$ = malloc(sizeof(struct expr));
            $$->expr.code = malloc(strlen($2.code) + 10);
            sprintf($$->expr.code, "(%s)", $2.code);
        }
        ;

%%

int main() {
    output_file = fopen("output.c", "w");
    if (!output_file) {
        fprintf(stderr, "Could not open output file\n");
        return 1;
    }
    yyparse();
    fclose(output_file);
    return 0;
}