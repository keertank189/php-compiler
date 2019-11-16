/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_START = 258,
     T_END = 259,
     T_BRK = 260,
     T_SCLN = 261,
     T_CBOP = 262,
     T_CBCL = 263,
     T_CNTUE = 264,
     T_IF = 265,
     T_PAOP = 266,
     T_PACL = 267,
     T_ELSE = 268,
     T_ELIF = 269,
     T_WHILE = 270,
     T_CLN = 271,
     T_SWITCH = 272,
     T_CASELABEL = 273,
     T_ID = 274,
     T_EQUALS = 275,
     T_INC = 276,
     T_DEC = 277,
     T_ADDEQ = 278,
     T_SUBEQ = 279,
     T_DIVEQ = 280,
     T_MULEQ = 281,
     T_STRING = 282,
     T_LOGOR = 283,
     T_LOGAND = 284,
     T_GREQ = 285,
     T_LEEQ = 286,
     T_GR = 287,
     T_LE = 288,
     T_EQCH = 289,
     T_TRUE = 290,
     T_FALSE = 291,
     T_NOT = 292,
     T_PLUS = 293,
     T_MINUS = 294,
     T_DIVIDE = 295,
     T_MUL = 296,
     T_MOD = 297,
     T_INT = 298,
     T_FLOAT = 299,
     T_COMMA = 300,
     T_ARR = 301,
     T_SQOP = 302,
     T_SQCL = 303,
     T_LOGXOR = 304,
     T_ECHO = 305,
     T_DOT = 306
   };
#endif
/* Tokens.  */
#define T_START 258
#define T_END 259
#define T_BRK 260
#define T_SCLN 261
#define T_CBOP 262
#define T_CBCL 263
#define T_CNTUE 264
#define T_IF 265
#define T_PAOP 266
#define T_PACL 267
#define T_ELSE 268
#define T_ELIF 269
#define T_WHILE 270
#define T_CLN 271
#define T_SWITCH 272
#define T_CASELABEL 273
#define T_ID 274
#define T_EQUALS 275
#define T_INC 276
#define T_DEC 277
#define T_ADDEQ 278
#define T_SUBEQ 279
#define T_DIVEQ 280
#define T_MULEQ 281
#define T_STRING 282
#define T_LOGOR 283
#define T_LOGAND 284
#define T_GREQ 285
#define T_LEEQ 286
#define T_GR 287
#define T_LE 288
#define T_EQCH 289
#define T_TRUE 290
#define T_FALSE 291
#define T_NOT 292
#define T_PLUS 293
#define T_MINUS 294
#define T_DIVIDE 295
#define T_MUL 296
#define T_MOD 297
#define T_INT 298
#define T_FLOAT 299
#define T_COMMA 300
#define T_ARR 301
#define T_SQOP 302
#define T_SQCL 303
#define T_LOGXOR 304
#define T_ECHO 305
#define T_DOT 306




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

