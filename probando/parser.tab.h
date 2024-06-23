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
    LT = 268,                      /* LT  */
    ELSE = 269,                    /* ELSE  */
    INDENT = 270,                  /* INDENT  */
    DEDENT = 271,                  /* DEDENT  */
    FALSE = 272,                   /* FALSE  */
    NONE = 273,                    /* NONE  */
    TRUE = 274,                    /* TRUE  */
    AND = 275,                     /* AND  */
    AS = 276,                      /* AS  */
    ASSERT = 277,                  /* ASSERT  */
    ASYNC = 278,                   /* ASYNC  */
    WAIT = 279,                    /* WAIT  */
    BREAK = 280,                   /* BREAK  */
    CLASS = 281,                   /* CLASS  */
    CONTINUE = 282,                /* CONTINUE  */
    DEF = 283,                     /* DEF  */
    DEL = 284,                     /* DEL  */
    ELIF = 285,                    /* ELIF  */
    EXCEPT = 286,                  /* EXCEPT  */
    FINALLY = 287,                 /* FINALLY  */
    FOR = 288,                     /* FOR  */
    FROM = 289,                    /* FROM  */
    GLOBAL = 290,                  /* GLOBAL  */
    IMPORT = 291,                  /* IMPORT  */
    IN = 292,                      /* IN  */
    IS = 293,                      /* IS  */
    LAMBDA = 294,                  /* LAMBDA  */
    NONLOCAL = 295,                /* NONLOCAL  */
    NOT = 296,                     /* NOT  */
    OR = 297,                      /* OR  */
    PASS = 298,                    /* PASS  */
    RAISE = 299,                   /* RAISE  */
    RETURN = 300,                  /* RETURN  */
    TRY = 301,                     /* TRY  */
    WHILE = 302,                   /* WHILE  */
    WITH = 303,                    /* WITH  */
    YIELD = 304                    /* YIELD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "parser.y"

    int int_val;
    float float_val;
    char *str;
    int indent;
    int dedent;

#line 121 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
