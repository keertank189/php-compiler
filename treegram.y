%{
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include<stdbool.h>
	#include "header.c"
	//#include "symbol_table.c"				
	#define YYSTYPE YACC
	FILE *yyin;
	FILE *fp;
	int yylex();

	void yyerror(const char *);

	
	AST* ast;
	TREE* nptr = NULL;

	TREE* newnode(char*,TREE*,TREE*,TREE*,TREE*);
	TREE* newleaf(char*,char*);
	//void display(TREE*);
	void printBT(char* prefix, TREE* node, int isLeft);
	
	FILE *yyin;
	int yylex();
	char *brlb,*contlb,*swlb,*swfal,*cslb[100],*wltr;
	int i =0;
	char* type;
	char* temp;
	char *var;
	int scope;
	int occur;
	int lbflag = 0;
	int tn = 1;
	int ln = 1;	
	DLIST *list;
	NODE *first;	
	SYMLIST *slist;
	/*typedef struct NODE
	{
		int valid;
		int dtype;
		int space;
		char name[100];
		union data_value
		{
			int i;
			float f;
			bool b;
			char string[150];
		};
		struct NODE *next;
	}NODE;
	typedef struct SYMBOL_TABLE
	{
		NODE *head;
		int entries;
	}TABLE;*/
	int scope = 0,occur = 0;
	

	
%}
//single tokens returned as yytext
//why id is without brackets
//how to pass strings
//is diveq okay> 

%error-verbose		
%token T_START T_END T_BRK T_SCLN T_CBOP T_CBCL T_CNTUE T_IF T_PAOP T_PACL T_ELSE T_ELIF T_WHILE T_CLN T_SWITCH T_CASELABEL T_ID T_EQUALS T_INC T_DEC T_ADDEQ T_SUBEQ T_DIVEQ T_MULEQ T_STRING T_LOGOR T_LOGAND T_GREQ T_LEEQ T_GR T_LE T_EQCH T_TRUE T_FALSE T_NOT T_PLUS T_MINUS T_DIVIDE T_MUL T_MOD T_INT T_FLOAT T_COMMA T_ARR T_SQOP T_SQCL T_LOGXOR T_ECHO T_DOT 
%start phpBlock


%%
phpBlock
	:T_START program T_END		{$$.ptr = $2.ptr;ast->root = $$.ptr;}
;

program
	:statement     				{$$.ptr = $1.ptr;}
;

singlestatement		
	: break								{$$.ptr = $1.ptr;}
	| continue							{$$.ptr = $1.ptr;}
	| if								{$$.ptr = $1.ptr;}
	| while								{$$.ptr = $1.ptr;}
	| switch  							{$$.ptr = $1.ptr;}
	| assignment						{$$.ptr = $1.ptr;}
	//| echo
;
statement
	: break statement 					{$$.ptr = newnode("stt",$1.ptr,$2.ptr,nptr,nptr);}			
	| block statement 					{$$.ptr = newnode("stt",$1.ptr,$2.ptr,nptr,nptr);}
	| continue statement 				{$$.ptr = newnode("stt",$1.ptr,$2.ptr,nptr,nptr);}
	| if statement 						{$$.ptr = newnode("stt",$1.ptr,$2.ptr,nptr,nptr);}
	| while statement 					{$$.ptr = newnode("stt",$1.ptr,$2.ptr,nptr,nptr);}
	| switch statement 					{$$.ptr = newnode("stt",$1.ptr,$2.ptr,nptr,nptr);}
	| assignment statement  			{$$.ptr = newnode("stt",$1.ptr,$2.ptr,nptr,nptr);}
	//| echo statement
	|									{$$.ptr = nptr;}
;

switch
	: T_SWITCH T_PAOP variable T_PACL T_CBOP cases T_CBCL {$$.ptr = newnode("switch",$3.ptr,$6.ptr,nptr,nptr);}  	
;

variable
	: T_ID index		{$$.ptr = newleaf("variable",$1.v);}	
;

index
	: T_SQOP T_INT T_SQCL index		{$$.ptr = newnode("index",$2.ptr,$4.ptr,nptr,nptr);}
	|	{$$.ptr = nptr;}							
;

cases 
	: T_CASELABEL switchconstant T_CLN insidecase cases  {$1.ptr = newleaf("keyword","case label");$$.ptr = newnode("case",$1.ptr,$2.ptr,$4.ptr,$5.ptr);}
	|	{$$.ptr = nptr;}	
;

insidecase
	: singlestatement 		{$$.ptr = $1.ptr;}
	| block 				{$$.ptr = $1.ptr;}
	|						{$$.ptr = nptr;}
;

switchconstant
	: T_INT					{$$.ptr = newleaf("int",$1.v);}
	| T_STRING				{$$.ptr = newleaf("string",$1.v);}
	| boolean				{$$.ptr = $1.ptr;}
;


while
	: T_WHILE T_PAOP logic_expr T_PACL block {$$.ptr = newnode("while",$3.ptr,$5.ptr,nptr,nptr);}
	| T_WHILE T_PAOP logic_expr T_PACL singlestatement 	{$$.ptr = newnode("while",$3.ptr,$5.ptr,nptr,nptr);}
	| T_WHILE T_PAOP logic_expr T_PACL T_SCLN {$$.ptr = newnode("while",$3.ptr,nptr,nptr,nptr);}
;

if
	: ifstmt block restofif				    {$$.ptr = newnode("if",$1.ptr,$2.ptr,$3.ptr,nptr);}
	| ifstmt singlestatement restofif 		{$$.ptr = newnode("if",$1.ptr,$2.ptr,$3.ptr,nptr);}

ifstmt 
	: T_IF T_PAOP logic_expr T_PACL 		{$$.ptr = $3.ptr;}
;

restofif
	: elseif else 						{$$.ptr = newnode("restofif",$1.ptr,$2.ptr,nptr,nptr);}
;

elseif
	: T_ELIF T_PAOP logic_expr T_PACL block elseif 					{$$.ptr = newnode("else if",$3.ptr,$5.ptr,$6.ptr,nptr);}
	| T_ELIF T_PAOP logic_expr T_PACL singlestatement elseif 		{$$.ptr = newnode("else if",$3.ptr,$5.ptr,$6.ptr,nptr);}
	|																{$$.ptr = newleaf("no else if","");}													
;

else
	: T_ELSE block 		{$$.ptr = newnode("else",$2.ptr,nptr,nptr,nptr);}										
	| T_ELSE singlestatement 	{$$.ptr = newnode("else",$2.ptr,nptr,nptr,nptr);}									
;

logic_expr
	: rel_expr 			{$$.ptr = $1.ptr;}			
	| rel_expr logic_op logic_expr {$$.ptr = newnode($2.v,$1.ptr,$3.ptr,nptr,nptr);}
;

logic_op
	: T_LOGOR 				{$$.v = strdup($1.v);}
	| T_LOGAND				{$$.v = strdup($1.v);}
	| T_LOGXOR				{$$.v = strdup($1.v);}
;


rel_expr
	: T_NOT T_PAOP rel_operand rel_op rel_operand T_PACL 
	| rel_operand rel_op rel_operand	{$$.ptr = newnode($2.v,$1.ptr,$3.ptr,nptr,nptr);}
	| rel_operand						{$$.ptr = $1.ptr;}
;

rel_op
	: T_GREQ	{$$.v = strdup($1.v);}
	| T_LEEQ	{$$.v = strdup($1.v);}
	| T_GR		{$$.v = strdup($1.v);}
	| T_LE 		{$$.v = strdup($1.v);}
	| T_EQCH 	{$$.v = strdup($1.v);}
;

rel_operand
	: variable		{$$.ptr = $1.ptr;}
	| rel_arith_expr {$$.ptr = $1.ptr;}
	| boolean 		{$$.ptr = $1.ptr;}
;

boolean
	: T_TRUE		{$$.ptr = newleaf("bool","true");}
	| T_FALSE		{$$.ptr = newleaf("bool","false");}
;

assignment
	: variable assign_op arith_expr T_SCLN  {$$.ptr = newnode($2.v,$1.ptr,$3.ptr,nptr,nptr);}
	| variable T_EQUALS T_STRING{$3.ptr = newleaf("string",$3.v);} T_SCLN {$$.ptr = newnode($2.v,$1.ptr,$3.ptr,nptr,nptr);}
	| prefix_op variable T_SCLN 	{$$.ptr = newnode($1.v,$2.ptr,nptr,nptr,nptr);}			
	| variable postfix_op T_SCLN 	{$$.ptr = newnode($2.v,$1.ptr,nptr,nptr,nptr);}
	| variable T_EQUALS array_declr T_SCLN
;

array_declr
	: T_ARR T_PAOP in_arr_list T_PACL
;

in_arr_list 
	: T_INT T_COMMA in_arr_list
	| T_FLOAT T_COMMA in_arr_list
	| boolean T_COMMA in_arr_list
	| array_declr T_COMMA in_arr_list
	| T_STRING T_COMMA in_arr_list
	|
;

prefix_op
	: T_INC			{$$.v = strdup($1.v);}	
	| T_DEC 		{$$.v = strdup($1.v);}
;

postfix_op
	: T_INC 		{$$.v = strdup($1.v);}	
	| T_DEC 		{$$.v = strdup($1.v);}
;


rel_arith_expr
	: rel_arith_expr T_PLUS rel_term 			{$$.ptr = newnode("+",$1.ptr,$3.ptr,nptr,nptr);}
	| rel_arith_expr T_MINUS rel_term 			{$$.ptr = newnode("-",$1.ptr,$3.ptr,nptr,nptr);}
	| rel_term									{$$.ptr = $1.ptr;}				
;

rel_term
	: rel_term T_MUL rel_factor 									{$$.ptr = newnode("*",$1.ptr,$3.ptr,nptr,nptr);}
	| rel_term T_DIVIDE rel_factor 									{$$.ptr = newnode("/",$1.ptr,$3.ptr,nptr,nptr);}
	| rel_term T_MOD rel_factor 									{$$.ptr = newnode("%",$1.ptr,$3.ptr,nptr,nptr);}
	| rel_factor 													{$$.ptr = $1.ptr;}					
;


rel_factor
	: rel_const 												{$$.ptr = $1.ptr;}
	| T_PAOP rel_arith_expr T_PACL 								{$$.ptr = $2.ptr;}

;

rel_const
	: T_INT					{$$.ptr = newleaf("int",$1.v);}			
	| T_FLOAT 				{$$.ptr = newleaf("float",$1.v);}			
	| T_STRING 				{$$.ptr = newleaf("string",$1.v);}			
;

arith_expr
	: arith_expr T_PLUS term 	{$$.ptr = newnode("+",$1.ptr,$3.ptr,nptr,nptr);}				
	| arith_expr T_MINUS term 	{$$.ptr = newnode("-",$1.ptr,$3.ptr,nptr,nptr);}				
	| term 						{$$.ptr = $1.ptr;}					
;

term
	: term T_MUL factor 					{$$.ptr = newnode("*",$1.ptr,$3.ptr,nptr,nptr);}		
	| term T_DIVIDE factor 					{$$.ptr = newnode("/",$1.ptr,$3.ptr,nptr,nptr);}		
	| term T_MOD factor 					{$$.ptr = newnode("%",$1.ptr,$3.ptr,nptr,nptr);}
	| factor 								{$$.ptr = $1.ptr;}								
;


factor
	: const 							{$$.ptr = $1.ptr;}
	| T_PAOP arith_expr T_PACL 			{$$.ptr = $2.ptr;}
	| variable 							{$$.ptr = $1.ptr;}

;

const
	: T_INT				{$$.ptr = newleaf("int",$1.v);}
	| T_FLOAT			{$$.ptr = newleaf("float",$1.v);}
;

assign_op
	: T_EQUALS			{$$.v = strdup($1.v);}
	| T_ADDEQ			{$$.v = strdup($1.v);}
	| T_SUBEQ			{$$.v = strdup($1.v);}
	| T_MULEQ			{$$.v = strdup($1.v);}
	| T_DIVEQ			{$$.v = strdup($1.v);}
;



block
	: T_CBOP statement T_CBCL				{$$.ptr = $2.ptr;}	
;

break
	: T_BRK T_SCLN 	{$$.ptr = newleaf("keyword","break");} 						
;

continue
	: T_CNTUE T_SCLN 	{$$.ptr = newleaf("keyword","continue");}					
;


%%
// if-else can switches be an empty block? switchconstant can't have empty singlestatement T_STRING strings default case

int main(int argc,char* argv[])
{
	fp = fopen("AST.txt", "w");
	ast = (AST*)malloc(sizeof(AST));
	ast->root = NULL;

	yyin = fopen(argv[1],"r");
	if(!yyparse()){
	
	printf("\n--------------------------------------");
	printf("\nParsing succesful\nCheck AST.txt for Abstract Syntax Tree\n");
	printf("--------------------------------------\n\n");

	fprintf(fp,"\n\n-------------------\n");
	fprintf(fp,"Abstract Sntax Tree\n");
	fprintf(fp,"-------------------\n\n");
	//display(ast->root);
	
	printBT("",ast->root,0);
	fprintf(fp,"\n");
	fclose(fp);
	}


return 0;

}


TREE* newnode(char* o,TREE* cc1,TREE* cc2,TREE* cc3, TREE* cc4)
{
	TREE* temp = (TREE*)malloc(sizeof(TREE));
	temp->opr= strdup(o);
	temp->value = strdup("N/A");
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
void printBT(char* prefix, TREE* node, int isLeft)
{	
	
	if(node==NULL)
		return;
    if( node != NULL)
    {
       fprintf(fp,"%s",prefix);

       	if(isLeft==0)
       		fprintf(fp,"└──");
       	else
       		fprintf(fp,"├──");
 
        // print the value of the node

     if(node->c1==NULL && node->c2==NULL && node->c3==NULL && node->c4==NULL)
	{
		
		fprintf(fp,"(%s, %s)\n",node->opr,node->value);
	}
	else
		fprintf(fp,"%s\n",node->opr);
        // enter the next tree level - left and right branch
        char new_prefix[1000];
       	if(isLeft==0){
       		strcpy(new_prefix,prefix);
       		strcat(new_prefix,"    ");
       	}
       	else
       		{
       		strcpy(new_prefix,prefix);
       		strcat(new_prefix,"│   ");
       	}


     if(node->c1!=NULL && node->c2==NULL && node->c3==NULL && node->c4==NULL)
	{
		printBT(new_prefix, node->c1, 0);
        printBT(new_prefix, node->c2, 0);
        printBT(new_prefix, node->c3, 0);
        printBT(new_prefix, node->c4, 0);
        return;
	}
	if(node->c1!=NULL && node->c2!=NULL && node->c3==NULL && node->c4==NULL)
	{
		printBT(new_prefix, node->c1, 1);
        printBT(new_prefix, node->c2, 0);
        printBT(new_prefix, node->c3, 0);
        printBT(new_prefix, node->c4, 0);
        return;
	}
	if(node->c1!=NULL && node->c2!=NULL && node->c3!=NULL && node->c4==NULL)
	{
		printBT(new_prefix, node->c1, 1);
        printBT(new_prefix, node->c2, 1);
        printBT(new_prefix, node->c3, 0);
        printBT(new_prefix, node->c4, 0);
        return;
	}	
	if(node->c1!=NULL && node->c2!=NULL && node->c3!=NULL && node->c4!=NULL)
	{
		printBT(new_prefix, node->c1, 1);
        printBT(new_prefix, node->c2, 1);
        printBT(new_prefix, node->c3, 1);
        printBT(new_prefix, node->c4, 0);
        return;
	}	
        
    }
    	
}



