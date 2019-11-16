%{
	#include <stdio.h>
	#include <string.h>
	#include "header.c"
	void yyerror(const char *);
	#include<stdlib.h>
	#define YYSTYPE YACC
	FILE *yyin;
	int yylex();
	AST* ast;
	TREE* nptr = NULL;

	TREE* newnode(char*,TREE*,TREE*,TREE*,TREE*);
	TREE* newleaf(char*,char*);
	void display(TREE*);
%}



%error-verbose


%left '*'
	

%token T_INT T_MAIN T_HASH T_INCLUDE T_IDENTIFIER T_HEADER_LITERAL T_STDIO T_STDLIB T_MATH T_STRING T_TIME T_VOID T_CHAR T_FLOAT T_OR_OP T_AND_OP	T_EQ_OP T_NE_OP T_LE_OP T_GE_OP T_INC_OP T_DEC_OP T_INTEGER_LITERAL T_FLOAT_LITERAL T_STRING_LITERAL T_CASE T_DEFAULT T_SWITCH T_FOR T_CONTINUE T_BREAK T_RETURN T_ADD_ASSIGN T_SUB_ASSIGN
%%
translation_unit 
	: external_declaration {
								$$.ptr = $1.ptr;
								ast->root = $$.ptr;

								
							}
	| translation_unit external_declaration {	
												$$.ptr = newnode("SEQ",$1.ptr,$2.ptr,nptr,nptr);
												ast->root  = $$.ptr;
											}
	;

external_declaration
	: T_INT T_MAIN '(' ')' compound_statement {$$.ptr = $5.ptr;}
	| declaration  {$$.ptr = $1.ptr;}
	| headers  {$$.ptr = $1.ptr;}
	;

headers
	: T_HASH T_INCLUDE T_HEADER_LITERAL {$$.ptr = newleaf("HEADER",$3.val);}
	| T_HASH T_INCLUDE '<' libraries '>' {$$.ptr = $4.ptr;}
	;

libraries
	: T_STDIO {$$.ptr = newleaf("stdio.h","N/A");}
	| T_STDLIB {$$.ptr = newleaf("stdlib.h","N/A");}
	| T_MATH {$$.ptr = newleaf("math.h","N/A");}
	| T_STRING {$$.ptr = newleaf("string.h","N/A");}
	| T_TIME {$$.ptr = newleaf("time.h","N/A");}
	;

declaration
	: type_specifier ';' {$$.ptr = newnode("DECL",$1.ptr,nptr,nptr,nptr);}
	| type_specifier init_declarator_list ';' {$$.ptr = newnode("DECL",$1.ptr,$2.ptr,nptr,nptr);}
	;

type_specifier
	: T_VOID {$$.ptr = newleaf("keyword","void");}
	| T_CHAR {$$.ptr = newleaf("keyword","char");}
	| T_INT  {$$.ptr = newleaf("keyword","int");}
	| T_FLOAT {$$.ptr = newleaf("keyword","float");}
	;



init_declarator_list
	: init_declarator {$$.ptr = $1.ptr;}
	| init_declarator_list ',' init_declarator {$$.ptr = newnode(",",$1.ptr,$3.ptr,nptr,nptr);}
	;

init_declarator
	: declarator '=' conditional_expression {$$.ptr = newnode("=",$1.ptr,$3.ptr,nptr,nptr);}
	| declarator {$$.ptr = $1.ptr;}
	;

declarator
	: T_IDENTIFIER {$$.ptr = newleaf("id",$1.val);}
	| declarator '[' ']'  {$$.ptr = $1.ptr;}
 	| declarator '['conditional_expression']' {$$.ptr = $1.ptr;}
	;

conditional_expression
	: logical_or_expression {$$.ptr = $1.ptr;}
 	| logical_or_expression '?' expression ':' conditional_expression {$$.ptr = newnode("TERNARY",$1.ptr,$3.ptr,$5.ptr,nptr);}
 	;

logical_or_expression
 	: logical_and_expression {$$.ptr = $1.ptr;}
 	| logical_or_expression T_OR_OP logical_and_expression {$$.ptr = newnode("||",$1.ptr,$3.ptr,nptr,nptr);}
	;

logical_and_expression
 	: equality_expression {$$.ptr = $1.ptr;}
 	| logical_and_expression T_AND_OP equality_expression {$$.ptr = newnode("&&",$1.ptr,$3.ptr,nptr,nptr);}
	; 

equality_expression
 	: relational_expression {$$.ptr = $1.ptr;}
 	| equality_expression T_EQ_OP relational_expression {$$.ptr = newnode("==",$1.ptr,$3.ptr,nptr,nptr);}
 	| equality_expression T_NE_OP relational_expression {$$.ptr = newnode("!=",$1.ptr,$3.ptr,nptr,nptr);}
 	;

relational_expression
 	: additive_expression {$$.ptr = $1.ptr;}
 	| relational_expression '<' additive_expression {$$.ptr = newnode("<",$1.ptr,$3.ptr,nptr,nptr);}
 	| relational_expression '>' additive_expression {$$.ptr = newnode(">",$1.ptr,$3.ptr,nptr,nptr);}
 	| relational_expression T_LE_OP additive_expression {$$.ptr = newnode("<=",$1.ptr,$3.ptr,nptr,nptr);}
 	| relational_expression T_GE_OP additive_expression {$$.ptr = newnode(">=",$1.ptr,$3.ptr,nptr,nptr);}
 	;


additive_expression
 	: multiplicative_expression {$$.ptr = $1.ptr;}
 	| additive_expression '+' multiplicative_expression {$$.ptr = newnode("+",$1.ptr,$3.ptr,nptr,nptr);}
 	| additive_expression '-' multiplicative_expression {$$.ptr = newnode("-",$1.ptr,$3.ptr,nptr,nptr);}
 	;

multiplicative_expression
 	: unary_expression {$$.ptr = $1.ptr;}
 	| multiplicative_expression '*' unary_expression {$$.ptr = newnode("*",$1.ptr,$3.ptr,nptr,nptr);}
 	| multiplicative_expression '/' unary_expression {$$.ptr = newnode("/",$1.ptr,$3.ptr,nptr,nptr);}
 	| multiplicative_expression '%' unary_expression {$$.ptr = newnode("%",$1.ptr,$3.ptr,nptr,nptr);}
 	;

unary_expression
 	: postfix_expression {$$.ptr = $1.ptr;}
 	| T_INC_OP unary_expression {$$.ptr = newnode("++",$1.ptr,nptr,nptr,nptr);}
 	| T_DEC_OP unary_expression {$$.ptr = newnode("--",$1.ptr,nptr,nptr,nptr);}
 	;

postfix_expression
 	: primary_expression {$$.ptr = $1.ptr;}
	| postfix_expression T_INC_OP {$$.ptr = newnode("++",$1.ptr,nptr,nptr,nptr);}
 	| postfix_expression T_DEC_OP {$$.ptr = newnode("--",$1.ptr,nptr,nptr,nptr);}
	; 

primary_expression
	: T_IDENTIFIER 		{$$.ptr = newleaf("id",$1.val);}
	| T_INTEGER_LITERAL {$$.ptr = newleaf("num",$1.val);}
	| T_FLOAT_LITERAL 	{$$.ptr = newleaf("num",$1.val);}
	| T_STRING_LITERAL 	{$$.ptr = newleaf("string",$1.val);}
	| '(' expression ')' {$$.ptr = $2.ptr;}
	;


statement
 	: labeled_statement {$$.ptr = $1.ptr;}
 	| compound_statement {$$.ptr = $1.ptr;}
 	| expression_statement {$$.ptr = $1.ptr;}
 	| selection_statement {$$.ptr = $1.ptr;}
 	| iteration_statement {$$.ptr = $1.ptr;}
 	| jump_statement {$$.ptr = $1.ptr;}
 	;

labeled_statement
 	: T_CASE conditional_expression ':' statement {$$.ptr = newnode("CASE",$2.ptr,$4.ptr,nptr,nptr);}
 	| T_DEFAULT ':' statement {$$.ptr = newnode("DEFAULT",$3.ptr,nptr,nptr,nptr);}
;

compound_statement
: '{' '}' {$$.ptr = newleaf("{ }","N/A");}
| '{' block_item_list '}' {$$.ptr = $2.ptr;}
;

block_item_list
	: block_item {$$.ptr = $1.ptr;}
	| block_item_list block_item {$$.ptr = newnode("SEQ",$1.ptr,$2.ptr,nptr,nptr);}
	;
block_item
	: declaration {$$.ptr = $1.ptr;}
	| statement {$$.ptr = $1.ptr;}
	;
expression_statement
 	: ';' {$$.ptr = newleaf(";","N/A");}
 	| expression ';' {$$.ptr = $1.ptr;}
 	;

 selection_statement
 	: T_SWITCH '(' expression ')' statement {$$.ptr = newnode("SWITCH",$3.ptr,$5.ptr,nptr,nptr);}
 	;

 iteration_statement
 	: T_FOR '(' expression_statement expression_statement ')' statement {$$.ptr = newnode("FOR",$3.ptr,$4.ptr,$6.ptr,nptr);}
	| T_FOR '(' expression_statement expression_statement expression ')' statement  {$$.ptr = newnode("FOR",$3.ptr,$4.ptr,$5.ptr,$7.ptr);}
	| T_FOR '(' declaration expression_statement ')' statement  {$$.ptr = newnode("FOR",$3.ptr,$4.ptr,$6.ptr,nptr);}
	| T_FOR '(' declaration expression_statement expression ')' statement  {$$.ptr = newnode("FOR",$3.ptr,$4.ptr,$5.ptr,$7.ptr);}
 	;

 jump_statement
	: T_CONTINUE ';' {$$.ptr = newleaf("keyword","continue");}
	| T_BREAK ';' {$$.ptr = newleaf("keyword","break");}
 	| T_RETURN ';' {$$.ptr = newleaf("keyword","return");}
 	| T_RETURN expression ';' {$$.ptr = newnode("return",$2.ptr,nptr,nptr,nptr);}
	;

expression
	: assignment_expression {$$.ptr = $1.ptr;}
	| expression ',' assignment_expression {$$.ptr = newnode(",",$1.ptr,$3.ptr,nptr,nptr);}
	;

assignment_expression
	: conditional_expression {$$.ptr = $1.ptr;}
	| unary_expression '=' assignment_expression {$$.ptr = newnode("=",$1.ptr,$3.ptr,nptr,nptr);}
	| unary_expression T_ADD_ASSIGN assignment_expression {$$.ptr = newnode("+=",$1.ptr,$3.ptr,nptr,nptr);} 
	| unary_expression T_SUB_ASSIGN assignment_expression {$$.ptr = newnode("-=",$1.ptr,$3.ptr,nptr,nptr);}
	;
%%

int main()
{
	ast = (AST*)malloc(sizeof(AST));
	ast->root = NULL;

yyin = fopen("test.c","r");
if(!yyparse()){
	printf("Parsing succesful\n\n");
	printf("-----------------------------------\n");
	printf("Abstract Sntax Tree (In Pre-Order)\n");
	printf("-----------------------------------\n");
	display(ast->root);
	printf("\n");
	}
else
	printf("Unsuccesful\n");
return 0;

}
void yyerror(const char *msg)
{
 printf("Invalid \n");
}


TREE* newnode(char* o,TREE* cc1,TREE* cc2,TREE* cc3, TREE* cc4)
{
	TREE* temp = (TREE*)malloc(sizeof(TREE));
	strcpy(temp->opr,o);
	strcpy(temp->value,"N/A");
	temp->c1 = cc1;
	temp->c2 = cc2;
	temp->c3 = cc3;
	temp->c4 = cc4;

	return temp;
}

TREE* newleaf(char* o, char* v)
{
	TREE* temp = (TREE*)malloc(sizeof(TREE));
	temp->opr = strdup(o);
	temp->value = strdup(v);
	temp->c1 = NULL;
	temp->c2 = NULL;
	temp->c3 = NULL;
	temp->c4 = NULL;

	return temp;
}

void display(TREE* r)
{	
	
	if(r==NULL)
		return;
	if(r->c1==NULL && r->c2==NULL && r->c3==NULL)
	{
		printf("(");
		printf("%s\t%s)\n",r->opr,r->value);
	}
	else
		printf("%s\n",r->opr);
	display(r->c1);
	display(r->c2);
	display(r->c3);
	display(r->c4);
}
