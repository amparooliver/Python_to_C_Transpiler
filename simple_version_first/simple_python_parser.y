%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();

typedef struct symbol {
    char *name;
    int type;
    struct symbol *next;
} symbol;

symbol *sym_table = NULL;

symbol *find_symbol(char *name);
void add_symbol(char *name, int type);

FILE *output_file; // File pointer for output

%}

%union {
    int num;
    float numf;
    char *str;
    int dedent;   // Añadido para representar el nivel de dedentación
    int indent;   // Añadido para representar el nivel de indentación
}

%token <str> ID
%token <num> INT
%token <numf> FLOAT
%token EQ SEMICOLON
%token INDENT DEDENT NEWLINE WHITESPACE 

%type <str> statement declaration assignment expression factor

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
    declaration
    |
    assignment
    ;

declaration:
    ID SEMICOLON {

    }
    |
    ;

assignment:
    ID EQ expression {
        symbol *sym = find_symbol($1);
        if (sym == NULL) {
            // Variable not found, create it
            add_symbol($1, INT); // Assuming default type is INT for simplicity
            fprintf(output_file, "int %s = %s;\n", $1, $3);
        } else {
            // Variable found, perform assignment
            fprintf(output_file, "%s = %s;\n", $1, $3);
        }
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
        symbol *sym = find_symbol($1);
        if (sym == NULL) {
            yyerror("Probando");
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

void add_symbol(char *name, int type) {
    symbol *s = (symbol *) malloc(sizeof(symbol));
    s->name = strdup(name);
    s->type = type;
    s->next = sym_table;
    sym_table = s;
}
