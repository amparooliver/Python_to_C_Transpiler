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

extern int bandera;
extern int line_counter;

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
%token IF COLON ELSE
%token <indent> INDENT 
%token <dedent> DEDENT
%token <str> FALSE TRUE

%token NONE AND AS ASSERT ASYNC WAIT BREAK CLASS CONTINUE DEF DEL
%token ELIF EXCEPT FINALLY FOR FROM GLOBAL IMPORT IN IS LAMBDA NONLOCAL NOT
%token OR PASS RAISE RETURN TRY WHILE WITH YIELD

%token PLUS MINUS MULTIPLY POWER DIVIDE FLOORDIV MOD MATMUL
%token LSHIFT RSHIFT BITAND BITOR BITXOR BITNOT WALRUS
%token LT GT LE GE DEQ NEQ

%token LBRACK RBRACK COMMA // Probando listas

%type <str> statement assignment conditional expression factor statements operation list_assignment list//keywords words

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
    |
    operation
    |
    list_assignment
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
list_assignment:
    ID EQ LBRACK list RBRACK {
        fprintf(stderr, "ID EQ list --> %s = [%s] \n", $1, $4);
        symbol *sym = find_symbol($1);
        if (sym == NULL) {
            add_symbol($1, "list");
            fprintf(output_file, "char* %s[] = {%s};\n", $1, $4);  // Declaración de lista
        } else {
            fprintf(output_file, "%s = {%s};\n", $1, $4);
        }
    }
    ;
list: 
    list COMMA factor {
        char buffer[256];
        sprintf(buffer, "%s, %s", $1, $3);
        $$ = strdup(buffer);
        free($1);
        free($3);
    }
    |
    factor {
        $$ = $1;
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
    INDENT statements DEDENT {
        fprintf(stderr, "entra a INDENT statements DEDENT\n");
        fprintf(stderr, "BANDERA: %d \n", bandera);
        for (int i = 0 ; i < bandera ; i += 4){
            fprintf(output_file, "} \n");
            fprintf(stderr, "valor i: %d \n", i);
        }
    }
    ;
operation:
    ID EQ expression PLUS expression{
        // No implementado
    }
    |
    ID EQ expression MINUS expression{
        // No implementado
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
    |
    STRING {
        $$ = $1;
    }
    |
    CHAR {
        char buffer[64];
        sprintf(buffer, "'%c'", $1[0]);
        $$ = strdup(buffer);
    }
    ;
    ;
/* 
keywords:
    words;
words:
    FALSE {
        char buffer[64];
        sprintf(buffer, "%s", $1);
        $$ = strdup(buffer);
    }
    |
    TRUE {
        char buffer[64];
        sprintf(buffer, "%s", $1);
        $$ = strdup(buffer);
    }
    ;
*/
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