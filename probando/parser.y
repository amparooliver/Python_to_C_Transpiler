%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();

typedef struct symbol {
    char *name;
    char *type;
    struct symbol *next;
    int indent;
} symbol;

symbol *sym_table = NULL;

symbol *find_symbol(char *name);
void add_symbol(char *name, char *type);

FILE *output_file; // File pointer for output

%}

%union {
    int int_val;
    float float_val;
    char *str;
    int indent;
    int dedent;
}

%token <str> ID CHAR STRING 
%token <int_val> INT
%token <float_val> FLOAT
%token EQ NEWLINE WHITESPACE 
%token IF COLON LT ELSE
%token <indent> INDENT 
token <dedent> DEDENT

%type <str> statement assignment conditional expression factor statements

%start program

%%

program:
    statements
    ;

statements:
    statements statement NEWLINE
    |
    statement NEWLINE
    ;

statement:
    assignment
    |
    conditional
    ;
assignment:
    ID EQ INT { // ASIGNACIONES Y DECLARACIONES INT
        fprintf(stderr, "ID EQ INT --> %s = %d \n ",$1, $3);
        symbol *sym = find_symbol($1);
        if (sym == NULL) {
            // Variable not found, create it
            add_symbol($1, "int"); 
            fprintf(output_file, "int %s = %d;\n", $1, $3);
        } else {
            // Variable found, perform assignment
            fprintf(output_file, "%s = %d;\n", $1, $3);
        }
    }
    |
    ID EQ FLOAT { // ASIGNACIONES Y DECLARACIONES FLOAT
        fprintf(stderr, "ID EQ FLOAT --> %s = %f \n ",$1, $3);
        symbol *sym = find_symbol($1);
        if (sym == NULL) {
            // Variable not found, create it
            add_symbol($1, "float"); 
            fprintf(output_file, "float %s = %f;\n", $1, $3);
        } else {
            // Variable found, perform assignment
            fprintf(output_file, "%s = %f;\n", $1, $3);
        }
    }
    |
    ID EQ CHAR { // ASIGNACIONES Y DECLARACIONES CHAR
        fprintf(stderr, "ID EQ CHAR --> %s = %s \n ",$1, $3);
        symbol *sym = find_symbol($1);
        if (sym == NULL) {
            // Variable not found, create it
            add_symbol($1, "char"); 
            fprintf(output_file, "char %s = %s;\n", $1, $3);
        } else {
            // Variable found, perform assignment // DEBERIA CONTROLAR SI ES CHAR?
            fprintf(output_file, "%s = %s;\n", $1, $3);
        }
    }
    |
    ID EQ STRING { // ASIGNACIONES Y DECLARACIONES CSTRING
        fprintf(stderr, "ID EQ STRING --> %s = %s \n ",$1, $3);
        symbol *sym = find_symbol($1);
        if (sym == NULL) {
            // Variable not found, create it
            add_symbol($1, "string"); 
            fprintf(output_file, "char %s[] = %s;\n", $1, $3);
        } else {
            // Variable found, perform assignment // DEBERIA CONTROLAR SI ES STRING?
            fprintf(output_file, "%s = %s;\n", $1, $3);
        }
    }
    ;

conditional: 
    /* IF expression LT expression COLON NEWLINE INDENT statements DEDENT{
        fprintf(stderr, "entra a exp < exp : \n ");
        fprintf(output_file, "if (%s < %s){ \n %s \n }", $2,$4,$8); 
    } */
    IF expression LT expression COLON{
        fprintf(stderr, "entra a exp < exp : \n ");
        fprintf(output_file, "if (%s < %s) {\n", $2, $4);
    }
    |
    INDENT statements{
        fprintf(output_file, "} \n");
        fprintf(stderr, "entra a INDENT statements\n");
    }

    ;
expression: 
    factor
    ;
factor:    
    INT {
        char buffer[64];
        sprintf(buffer, "%d", $1);
        $$ = strdup(buffer);
    }
    |
    FLOAT {
        char buffer[64];
        sprintf(buffer, "%f", $1);
        $$ = strdup(buffer);
    }
    |
    ID { 
        fprintf(stderr, "entra a ID de FACTOR \n ");
        symbol *sym = find_symbol($1);
        if (sym == NULL) {
            yyerror("Variable no definida");
        } else {
            $$ = $1;
        }
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    fprintf(stderr, "se ejecuta el main \n ");
    output_file = fopen("output.c", "w");
    if (!output_file) {
        perror("Failed to create output file");
        return 1;
    }

    yyparse();

    fclose(output_file);

    return 0;
}

symbol *find_symbol(char *name) {
    symbol *s = sym_table;
    while (s != NULL) {
        if (strcmp(s->name, name) == 0) {
            return s;
        }
        s = s->next;
    }
    return NULL;
}

void add_symbol(char *name, char *type) {
    symbol *s = (symbol *) malloc(sizeof(symbol));
    s->name = strdup(name);
    s->type = type;
    s->next = sym_table;
    sym_table = s;
}