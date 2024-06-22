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
}

%token <str> ID CHAR STRING
%token <int_val> INT
%token <float_val> FLOAT
%token EQ 

%type <str> statement assignment 

%start program

%%

program:
    statements
    ;

statements:
    statements statement
    |
    statement
    ;

statement:
    assignment
    ;

assignment:
    ID EQ INT { // ASIGNACIONES Y DECLARACIONES INT
        fprintf(stderr, "entra al int %d \n ",$3);
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
        fprintf(stderr, "entra al float \n ");
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
        fprintf(stderr, "entra al char \n ");
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
        fprintf(stderr, "entra al string \n ");
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
