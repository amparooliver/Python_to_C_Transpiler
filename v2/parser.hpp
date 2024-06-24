/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER = 259,                 /* INTEGER  */
    BOOLEAN = 260,                 /* BOOLEAN  */
    FLOAT = 261,                   /* FLOAT  */
    STRING = 262,                  /* STRING  */
    EQUALS = 263,                  /* EQUALS  */
    PLUS = 264,                    /* PLUS  */
    MINUS = 265,                   /* MINUS  */
    TIMES = 266,                   /* TIMES  */
    DIVIDEDBY = 267,               /* DIVIDEDBY  */
    EQ = 268,                      /* EQ  */
    NEQ = 269,                     /* NEQ  */
    GT = 270,                      /* GT  */
    GTE = 271,                     /* GTE  */
    LT = 272,                      /* LT  */
    LTE = 273,                     /* LTE  */
    RETURN = 274,                  /* RETURN  */
    INDENT = 275,                  /* INDENT  */
    DEDENT = 276,                  /* DEDENT  */
    NEWLINE = 277,                 /* NEWLINE  */
    IF = 278,                      /* IF  */
    COLON = 279,                   /* COLON  */
    AND = 280,                     /* AND  */
    BREAK = 281,                   /* BREAK  */
    DEF = 282,                     /* DEF  */
    ELIF = 283,                    /* ELIF  */
    ELSE = 284,                    /* ELSE  */
    FOR = 285,                     /* FOR  */
    NOT = 286,                     /* NOT  */
    OR = 287,                      /* OR  */
    WHILE = 288,                   /* WHILE  */
    SEMICOLON = 289,               /* SEMICOLON  */
    LPAREN = 290,                  /* LPAREN  */
    RPAREN = 291,                  /* RPAREN  */
    COMMA = 292,                   /* COMMA  */
    LBRACK = 293,                  /* LBRACK  */
    RBRACK = 294                   /* RBRACK  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "parser.y"

  float value;
  std::string* str;
  int token;

#line 109 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




#ifndef YYPUSH_MORE_DEFINED
# define YYPUSH_MORE_DEFINED
enum { YYPUSH_MORE = 4 };
#endif

typedef struct yypstate yypstate;


int yypush_parse (yypstate *ps,
                  int pushed_char, YYSTYPE const *pushed_val, YYLTYPE *pushed_loc);

yypstate *yypstate_new (void);
void yypstate_delete (yypstate *ps);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
