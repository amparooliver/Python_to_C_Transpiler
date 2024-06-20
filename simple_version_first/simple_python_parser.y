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
    char *str;
}

%token <str> IDENTIFIER
%token <num> NUMBER
%token INT FLOAT ASSIGN SEMICOLON

%type <str> statement declaration assignment expression factor
%type <num> type

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
    type IDENTIFIER SEMICOLON {
        add_symbol($2, $1); // Add variable to the symbol table
        fprintf(output_file, "%s %s;\n", $1 == 1 ? "int" : "float", $2);
    }
    |
    type IDENTIFIER ASSIGN expression SEMICOLON {
        add_symbol($2, $1); // Add variable to the symbol table
        fprintf(output_file, "%s %s = %s;\n", $1 == 1 ? "int" : "float", $2, $4);
    }
    ;

assignment:
    IDENTIFIER ASSIGN expression {
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
    NUMBER {
        char buffer[64];
        sprintf(buffer, "%d", $1);
        $$ = strdup(buffer);
    }
    |
    IDENTIFIER {
        symbol *sym = find_symbol($1);
        if (sym == NULL) {
            yyerror("Probando");
        } else {
            $$ = $1;
        }
    }
    ;

type:
    INT { $$ = 1; }
    |
    FLOAT { $$ = 2; }
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
