%{
	#include "header.c"
	#define YYSTYPE YACC
	#include "y.tab.h"
	#include<string.h>
	#include<stdio.h>
	int lincount=1;
%}

%%
"<?php"						{yylval.v = strdup(yytext);return T_START;}
"?>"						{yylval.v = strdup(yytext);return T_END;}
"break"						{yylval.v = strdup(yytext);return T_BRK;yylval.v = strdup(yytext);}
"{"							{yylval.v = strdup(yytext);return T_CBOP;yylval.v = strdup(yytext);}
"}"							{yylval.v = strdup(yytext);return T_CBCL;yylval.v = strdup(yytext);}
"continue"					{yylval.v = strdup(yytext);return T_CNTUE;yylval.v = strdup(yytext);}
"if"						{yylval.v = strdup(yytext);return T_IF;yylval.v = strdup(yytext);}
"("							{yylval.v = strdup(yytext);return T_PAOP;yylval.v = strdup(yytext);}
"!"							{yylval.v = strdup(yytext);return T_NOT;yylval.v = strdup(yytext);}	
")"							{yylval.v = strdup(yytext);return T_PACL;yylval.v = strdup(yytext);}
"else"						{yylval.v = strdup(yytext);return T_ELSE;yylval.v = strdup(yytext);}
"elseif"					{yylval.v = strdup(yytext);return T_ELIF;yylval.v = strdup(yytext);}
"while"						{yylval.v = strdup(yytext);return T_WHILE;yylval.v = strdup(yytext);}
"switch"					{yylval.v = strdup(yytext);return T_SWITCH;yylval.v = strdup(yytext);}
"array"						{yylval.v = strdup(yytext);return T_ARR;yylval.v = strdup(yytext);}
","							{yylval.v = strdup(yytext);return T_COMMA;yylval.v = strdup(yytext);}
"["							{yylval.v = strdup(yytext);return T_SQOP;yylval.v = strdup(yytext);}
"]"							{yylval.v = strdup(yytext);return T_SQCL;yylval.v = strdup(yytext);}
"case"						{yylval.v = strdup(yytext);return T_CASELABEL;yylval.v = strdup(yytext);}
":"							{yylval.v = strdup(yytext);return T_CLN;yylval.v = strdup(yytext);}
"$"[_a-zA-Z][a-zA-Z0-9]*	{yylval.v = strdup(yytext);return T_ID; yylval.v = strdup(yytext);}
[0-9][0-9]*					{yylval.v = strdup(yytext);return T_INT;yylval.v = strdup(yytext);}
[0-9][0-9]*"."[0-9][0-9]*	{yylval.v = strdup(yytext);return T_FLOAT;yylval.v = strdup(yytext);}
"="							{yylval.v = strdup(yytext);return T_EQUALS;yylval.v = strdup(yytext);}
"++"						{yylval.v = strdup(yytext);return T_INC;yylval.v = strdup(yytext);}
"--"						{yylval.v = strdup(yytext);return T_DEC;yylval.v = strdup(yytext);}
"+="						{yylval.v = strdup(yytext);return T_ADDEQ;yylval.v = strdup(yytext);}
"-="						{yylval.v = strdup(yytext);return T_SUBEQ;yylval.v = strdup(yytext);}
"/="						{yylval.v = strdup(yytext);return T_DIVEQ;yylval.v = strdup(yytext);}
"*="						{yylval.v = strdup(yytext);return T_MULEQ;yylval.v = strdup(yytext);}
"&&"						{yylval.v = strdup(yytext);return T_LOGAND;yylval.v = strdup(yytext);}
"||"						{yylval.v = strdup(yytext);return T_LOGOR;yylval.v = strdup(yytext);}
"xor"						{yylval.v = strdup(yytext);return T_LOGXOR;yylval.v = strdup(yytext);}
"echo"						{yylval.v = strdup(yytext);return T_ECHO;yylval.v = strdup(yytext);}
"."							{yylval.v = strdup(yytext);return T_DOT;yylval.v = strdup(yytext);}
">="						{yylval.v = strdup(yytext);return T_GREQ;yylval.v = strdup(yytext);}
"<="						{yylval.v = strdup(yytext);return T_LEEQ;yylval.v = strdup(yytext);}
">"							{yylval.v = strdup(yytext);return T_GR;yylval.v = strdup(yytext);}
"<"							{yylval.v = strdup(yytext);return T_LE;yylval.v = strdup(yytext);}
"=="						{yylval.v = strdup(yytext);return T_EQCH;yylval.v = strdup(yytext);}
"true"						{yylval.v = strdup(yytext);return T_TRUE;yylval.v = strdup(yytext);}
"false"						{yylval.v = strdup(yytext);return T_FALSE;yylval.v = strdup(yytext);}
"+"							{yylval.v = strdup(yytext);return T_PLUS;yylval.v = strdup(yytext);}
"-"							{yylval.v = strdup(yytext);return T_MINUS;yylval.v = strdup(yytext);}
"/"							{yylval.v = strdup(yytext);return T_DIVIDE;yylval.v = strdup(yytext);}
"*"							{yylval.v = strdup(yytext);return T_MUL;yylval.v = strdup(yytext);}
"%"							{yylval.v = strdup(yytext);return T_MOD;yylval.v = strdup(yytext);}
";"							{yylval.v = strdup(yytext);return T_SCLN;yylval.v = strdup(yytext);}
["][^\"\n]*["]					{yylval.v = strdup(yytext);return T_STRING;yylval.v = strdup(yytext);}
"\n"		{lincount++;}
.			{}

%%
void yyerror(const char *err)
{
	printf("\nError at line no : %d\n",lincount);
}
int yywrap()
{
	return 1;
}