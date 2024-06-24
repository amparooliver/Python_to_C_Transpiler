%{
#include <iostream>
#include <map>
#include <algorithm> // Incluir para std::find
#include <cstring>
#include <sstream> // Para usar std::stringstream
#include <string>  // Para usar std::string

#include "parser.hpp"

std::map<std::string, std::string> symbol_table; // Tabla de símbolos
std::string* goalStr;

void yyerror(YYLTYPE* loc, const char* err);
extern int yylex();

int bandera = 0;

%}

%union {
  float value;
  std::string* str;
  int token;
}

%locations

%define api.pure full
%define api.push-pull push

%token <str> IDENTIFIER INTEGER BOOLEAN FLOAT STRING
%token <token> EQUALS PLUS MINUS TIMES DIVIDEDBY
%token <token> EQ NEQ GT GTE LT LTE RETURN
%token <token> INDENT DEDENT NEWLINE IF COLON
%token <token> AND BREAK DEF ELIF ELSE FOR NOT OR WHILE
%token <token> SEMICOLON LPAREN RPAREN COMMA LBRACK RBRACK

%type <str> expression statement list elements
%type <str> conditional conditionalExpr ifelse
%type <str> flowcontrol program

%left PLUS MINUS 
%left TIMES DIVIDEDBY

%start goal

%%

goal
  : program { }

program
  : program statement {$$ = new std::string(*$1 + *$2);
                      goalStr = new std::string(*$$);
                      delete $1; delete $2; 
                       }
  | statement { $$ = new std::string(*$1); delete $1; }
  ;

statement
  : conditional {$$ = new std::string(*$1); delete $1; }
  | DEDENT conditional statement DEDENT DEDENT { $$ = new std::string("} " + *$2 + "\n" + *$3 + "}\n}\n"); delete $2; delete $3;}
  | DEDENT { $$ = new std::string("}"); }
  | INDENT statement {$$ = new std::string(*$2); delete $2; }
  | INDENT statement INDENT statement { std::cerr << "Error:"<< "Indentation error"<< std::endl; exit(1); delete $2; delete $4; }
  | INDENT flowcontrol NEWLINE DEDENT DEDENT { $$ = new std::string(*$2 + "; \n}\n}\n"); delete $2; }
  | IDENTIFIER EQUALS expression NEWLINE {
        // Si no existe el id, se genera una declaracion
        if (symbol_table.find(*$1) == symbol_table.end()) {
            // Determina el tipo del identificador
            std::string type;
            if (bandera == 1) type = "int";
            else if (bandera == 2) type = "float";
            else if (bandera == 3) type = "bool";
            else if (bandera == 4) type = "char";
            else if (bandera == 5) type = "array";
            else {
                std::cerr << "Error: Tipo no reconocido para el identificador '" << *$1 << "'" << std::endl;
                exit(1);
            }

            // Agrega el identificador a la tabla de símbolos con su tipo
            symbol_table[*$1] = type;
            // Construye la cadena de asignación para el output.c
            std::stringstream ss;
            if (type == "char"){
                ss << type << " " << *$1 << "[] = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }else{
                ss << type << " " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }
 

        } else {
            // Si el identificador ya existe en la tabla de símbolos, asigna la expresión al identificador existente
            $$ = new std::string(*$1 + " = " + *$3 + ";\n");
        }

        // Limpia la memoria de los punteros utilizados
        delete $1; delete $3;
    }
  ; 

expression
  : INTEGER { bandera = 1; $$ = $1; }
  | FLOAT { bandera = 2; $$ = $1; }
  | BOOLEAN { bandera = 3; $$ = $1; }
  | IDENTIFIER {$$ = $1; }
  | STRING {  bandera = 4; $$ = $1; }
  | LPAREN expression RPAREN {  $$ = new std::string("(" + *$2 + ")"); delete $2;}
  | expression PLUS expression { $$ =  new std::string(*$1 + " + " + *$3); delete $1; delete $3;} 
  | expression MINUS expression { $$ =  new std::string(*$1 + " - " + *$3); delete $1; delete $3;} 
  | expression TIMES expression { $$ =  new std::string(*$1 + " * " + *$3); delete $1; delete $3;} 
  | expression DIVIDEDBY expression { $$ =  new std::string(*$1 + " / " + *$3); delete $1; delete $3;}  
  | list { bandera = 5; $$ = $1; }                              
  ;
list
  : LBRACK RBRACK { $$ = new std::string("[]"); }
  | LBRACK elements RBRACK { $$ = new std::string("[" + *$2 + "]"); delete $2; }
  ;
elements
  : expression { $$ = new std::string(*$1); delete $1; }
  | elements COMMA expression { $$ = new std::string(*$1 + ", " + *$3); delete $1; delete $3; }
  ;
conditionalExpr
  : IDENTIFIER { $$ = $1; }
  | INTEGER { $$ = $1; }
  | FLOAT { $$ = $1; }
  | BOOLEAN { $$ = $1; }
  | conditionalExpr LT conditionalExpr { $$ = new std::string(*$1 + " < " + *$3);  delete $1; delete $3;}
  | conditionalExpr GT conditionalExpr { 
                                        $$ = new std::string(*$1 + " > " + *$3);
                                        delete $1; delete $3;
                                      }
  | conditionalExpr LTE conditionalExpr {  $$ = new std::string(*$1 + " <= " + *$3); delete $1; delete $3;}
  | conditionalExpr GTE conditionalExpr {  $$ = new std::string(*$1 + " >= " + *$3); delete $1; delete $3;}
  | conditionalExpr NEQ conditionalExpr {  $$ = new std::string(*$1 + " != " + *$3); delete $1; delete $3;}
  | conditionalExpr EQ conditionalExpr {  $$ = new std::string(*$1 + " == " + *$3); delete $1; delete $3;}
  ;

conditional
  : ifelse
  | WHILE conditionalExpr COLON NEWLINE { $$ = new std::string("while (" + *$2 + ") {\n"); delete $2;}
  ;

ifelse
  : IF conditionalExpr COLON NEWLINE {  $$ = new std::string("if(" + *$2 + ") {\n"); delete $2;
                                }
  | ELSE COLON NEWLINE { $$ = new std::string("else {"); };
  ;

flowcontrol
  : BREAK { $$ = new std::string("break"); }
  ;

%%

void yyerror(YYLTYPE* loc, const char* err) {
  std::cerr << "Error: " << err << std::endl;

}
