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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    ID = 258,                      /* ID  */
    CHAR = 259,                    /* CHAR  */
    STRING = 260,                  /* STRING  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    EQ = 263,                      /* EQ  */
    NEWLINE = 264,                 /* NEWLINE  */
    WHITESPACE = 265,              /* WHITESPACE  */
    IF = 266,                      /* IF  */
    COLON = 267,                   /* COLON  */
    ELSE = 268,                    /* ELSE  */
    INDENT = 269,                  /* INDENT  */
    DEDENT = 270,                  /* DEDENT  */
    FALSE = 271,                   /* FALSE  */
    TRUE = 272,                    /* TRUE  */
    NONE = 273,                    /* NONE  */
    AND = 274,                     /* AND  */
    AS = 275,                      /* AS  */
    ASSERT = 276,                  /* ASSERT  */
    ASYNC = 277,                   /* ASYNC  */
    WAIT = 278,                    /* WAIT  */
    BREAK = 279,                   /* BREAK  */
    CLASS = 280,                   /* CLASS  */
    CONTINUE = 281,                /* CONTINUE  */
    DEF = 282,                     /* DEF  */
    DEL = 283,                     /* DEL  */
    ELIF = 284,                    /* ELIF  */
    EXCEPT = 285,                  /* EXCEPT  */
    FINALLY = 286,                 /* FINALLY  */
    FOR = 287,                     /* FOR  */
    FROM = 288,                    /* FROM  */
    GLOBAL = 289,                  /* GLOBAL  */
    IMPORT = 290,                  /* IMPORT  */
    IN = 291,                      /* IN  */
    IS = 292,                      /* IS  */
    LAMBDA = 293,                  /* LAMBDA  */
    NONLOCAL = 294,                /* NONLOCAL  */
    NOT = 295,                     /* NOT  */
    OR = 296,                      /* OR  */
    PASS = 297,                    /* PASS  */
    RAISE = 298,                   /* RAISE  */
    RETURN = 299,                  /* RETURN  */
    TRY = 300,                     /* TRY  */
    WHILE = 301,                   /* WHILE  */
    WITH = 302,                    /* WITH  */
    YIELD = 303,                   /* YIELD  */
    PLUS = 304,                    /* PLUS  */
    MINUS = 305,                   /* MINUS  */
    MULTIPLY = 306,                /* MULTIPLY  */
    POWER = 307,                   /* POWER  */
    DIVIDE = 308,                  /* DIVIDE  */
    FLOORDIV = 309,                /* FLOORDIV  */
    MOD = 310,                     /* MOD  */
    MATMUL = 311,                  /* MATMUL  */
    LSHIFT = 312,                  /* LSHIFT  */
    RSHIFT = 313,                  /* RSHIFT  */
    BITAND = 314,                  /* BITAND  */
    BITOR = 315,                   /* BITOR  */
    BITXOR = 316,                  /* BITXOR  */
    BITNOT = 317,                  /* BITNOT  */
    WALRUS = 318,                  /* WALRUS  */
    LT = 319,                      /* LT  */
    GT = 320,                      /* GT  */
    LE = 321,                      /* LE  */
    GE = 322,                      /* GE  */
    DEQ = 323,                     /* DEQ  */
    NEQ = 324                      /* NEQ  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"

    int int_val;
    float float_val;
    char *str;
    int indent;
    int dedent;

#line 141 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
