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
//std::string funcProcStr[2];

void yyerror(YYLTYPE* loc, const char* err);
extern int yylex();
extern int yylineno;

int tipo_actual = 0;
int tipo_actual2 = 0;

%}

%union {
  float value;
  std::string* str;
  int token;
}

%locations

%define api.pure full
%define api.push-pull push

%token <str> IDENTIFIER INTEGER TBOOLEAN FBOOLEAN FLOAT STRING DOUBLE CONSTANT
%token <token> EQUALS PLUS MINUS TIMES DIVIDEDBY
%token <token> EQ NEQ GT GTE LT LTE RETURN
%token <token> INDENT DEDENT NEWLINE IF COLON
%token <token> AND BREAK ELIF ELSE FOR IN RANGE NOT OR WHILE DEF
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
  | INDENT statement {$$ = new std::string(*$2); delete $2; }//std::cerr << "Entro a INDENT statement\n";}
  /*| INDENT statement INDENT statement { std::cerr << "Error:"<< "Indentation error"<< std::endl; exit(1); delete $2; delete $4; }*/
  | INDENT flowcontrol NEWLINE DEDENT DEDENT { $$ = new std::string(*$2 + "; \n}\n}\n"); delete $2; }
  | IDENTIFIER EQUALS expression NEWLINE {
        // Si no existe el id, se genera una declaracion
        if (symbol_table.find(*$1) == symbol_table.end()) {
            // Determina el tipo del identificador
            std::string type;
            if (tipo_actual == 1 | tipo_actual == 6 ) type = "int";
            else if (tipo_actual == 2) type = "float";
            else if (tipo_actual == 3) type = "bool";
            else if (tipo_actual == 4) type = "char";
            else if (tipo_actual == 5) type = "lista";
            else if (tipo_actual == 7) type = "double";
            else {
                std::cerr << "Error: Tipo no reconocido para el identificador '" << *$1 << "'. En linea: " << yylineno << std::endl;
                exit(1);
            }
            // Agrega el identificador a la tabla de símbolos con su tipo
            symbol_table[*$1] = type;
            // Construye la cadena de asignación para el output.c
            std::stringstream ss;
            if (type == "char"){
                ss << type << " " << *$1 << "[] = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }else if(type == "lista" && tipo_actual2 == 1){ // ES UN ARRAY INT
                ss << "int " << *$1 << "[] = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }else if(type == "lista" && tipo_actual2 == 2){ // ES UN ARRAY FLOAT
                ss << "float " << *$1 << "[] = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }
            else if(type == "lista" && tipo_actual2 == 3){ // ES UN ARRAY CHAR ARRAY (ojo que acepta sitring tb y deberia ser otra declaracion)
                ss << "char " << *$1 << "[] = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }
            else{
                ss << type << " " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }

        } else { $$ = new std::string(*$1 + " = " + *$3 + ";\n"); } // Ya existe entonces, se asigna nada mas
          tipo_actual = 0;
          tipo_actual2 = 0;
        // Limpia la memoria de los punteros utilizados
        delete $1; delete $3;
    }
    | CONSTANT EQUALS expression NEWLINE {
        // Si no existe el id, se genera una declaracion
        if (symbol_table.find(*$1) == symbol_table.end()) {
            // Determina el tipo de la constante
            std::string type;
            std::stringstream ss;
            if(tipo_actual2 == 1){ 
                type = "const int";
                ss << "const int " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*$1] = type;
            }else if(tipo_actual2 == 2){ 
                type = "const float";
                ss << "const float " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*$1] = type;
            }
            else if(tipo_actual2 == 3){ 
                type = "const char";
                ss << "const char " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*$1] = type;
            }
            else{
              std::cerr << "Error: Asignacion no valida a constante " << *$1 << ". En linea: " << yylineno << std::endl;
            }
            delete $1; delete $3;
        }else{
          // Si existe no se puede modificar

          std::cerr << "Error: Modificacion no valida a constante " << *$1 << ". En linea: " << yylineno << std::endl;
          delete $1; delete $3;
           exit(1);
        }
        tipo_actual = 0;
        tipo_actual2 = 0;
        // Limpia la memoria de los punteros utilizados
        
    }
    | FOR IDENTIFIER IN RANGE LPAREN INTEGER RPAREN COLON NEWLINE{
        $$ = new std::string("for (int " + *$2 + " = 0; " + *$2 + " <  " + *$6 + "; " + *$2 + "++) {\n"); delete $2; delete $6;
    }/*
    | DEF IDENTIFIER LPAREN IDENTIFIER RPAREN COLON NEWLINE{
          //std::cerr << "ENTRO A DEF" << std::endl;
          std::stringstream ss;
          ss << "void " << *$2 << "( int "+ *$4 + ") {\n";
          funcProcStr[0].append(ss.str());
        // Agrego a la tabla de simbolos con type proc
        symbol_table[*$2] = "proc";
        delete $2; delete $4;
    }
    | IDENTIFIER LPAREN expression RPAREN NEWLINE {
      //std::cerr << "ENTRO A llamada" << std::endl;
      $$ = new std::string(*$1 +"("+ *$3 + ")"); delete $1; delete $3;
    }*/
  ; 

expression
  : INTEGER { tipo_actual = 1; tipo_actual2 = 1; $$ = $1; }
  | FLOAT { tipo_actual = 2; tipo_actual2 = 2; $$ = $1; }
  | DOUBLE { tipo_actual = 7; $$ = $1; }
  | TBOOLEAN { tipo_actual = 3; $$ = $1; }
  | FBOOLEAN { tipo_actual = 3; $$ = $1; }
  | IDENTIFIER {tipo_actual = 6;$$ = $1; }
  | CONSTANT {tipo_actual = 8;$$ = $1; }
  | STRING {  tipo_actual = 4; tipo_actual2 = 3; $$ = $1; }
  | LPAREN expression RPAREN {  $$ = new std::string("(" + *$2 + ")"); delete $2;}
  | expression PLUS expression { $$ =  new std::string(*$1 + " + " + *$3); delete $1; delete $3;} 
  | expression MINUS expression { $$ =  new std::string(*$1 + " - " + *$3); delete $1; delete $3;} 
  | expression TIMES expression { $$ =  new std::string(*$1 + " * " + *$3); delete $1; delete $3;} 
  | expression DIVIDEDBY expression { $$ =  new std::string(*$1 + " / " + *$3); delete $1; delete $3;}  
  | list { tipo_actual = 5; $$ = $1; }                              
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
  | TBOOLEAN { $$ = $1; }
  | FBOOLEAN { $$ = $1; }
  | STRING { $$ = $1; }
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
  : IF conditionalExpr COLON NEWLINE {  $$ = new std::string("if(" + *$2 + ") {\n"); delete $2;}
  | ELSE COLON NEWLINE { $$ = new std::string("else {"); };
  ;

flowcontrol
  : BREAK { $$ = new std::string("break"); }
  ;

%%

void yyerror(YYLTYPE* loc, const char* err) {
  std::cerr << "Error: " << err << std::endl;

}
