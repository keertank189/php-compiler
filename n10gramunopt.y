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
	
	void printlist(DLIST *list);
	void addNode(DLIST *list,int open);

	void addVar(char *name,char *val,char *type,int scope,int occur,SYMLIST *slist);
	void printsym(SYMLIST *slist);

	SYMNODE* varsearch(char *name,SYMNODE *stemp,NODE *temp);
	SYMNODE* lookup(char *name,SYMLIST *slist, DLIST *list);
	
	FILE *yyin;
	int yylex();
	char *brlb,*contlb,*swlb,*swfal,*cslb[100],*wltr;
	int i =0;
	char* type;
	char* temp;
	char *var;
	int scope;
	int occur;
	char* newLabel(int *ln);
	char* newTemp(int *tn);
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
	:{slist = (SYMLIST*)malloc(sizeof(SYMLIST));slist->head = NULL;list = (DLIST*)malloc(sizeof(DLIST));first= (NODE*)malloc(sizeof(NODE));first->prev = NULL;first->next = NULL;first->scope = scope;first->occur = occur;list->head = first;}T_START program T_END	{printf("\nScoping for the whole grammar\n");printlist(list);printf("\nSYMBOL TABLE FOR THE WHOLE GRAMMAR:\n");printsym(slist);}		
;

program
	:statement     						
;

singlestatement		
	: break								//{$$.code = $1.code;}
	| continue							//{$$.code = $1.code;}
	| if								//{$$.code = $1.code;}
	| while								//{$$.code = $1.code;}
	| switch  							//{$$.code = $1.code;}
	| assignment						//{$$.code = $1.code;}
	//| echo
;
statement
	: break statement 					//{$$.code = "";} //FINISHHHH
	| block statement 					//{$$.code = "";} //FINISHHHH
	| continue statement 				//{$$.code = "";} //FINISHHHH
	| if statement 						//{$$.code = (char*)malloc(sizeof(char)*(strlen($1.code)+strlen($2.code)) + 1); strcat($$.code,$1.code);strcat($$.code,$2.code);}
	| while statement 					//{$$.code = "";} //FINISHHHH
	| switch statement 					//{$$.code = "";} //FINISHHHH
	| assignment statement  			//{$$.code = "";} //FINISHHHH
	//| echo statement
	|									//{$$.code = "";}
;

switch
	: T_SWITCH {$$.tr = newLabel(&ln); $$.fal = newLabel(&ln); $$.code = (char*)malloc(sizeof(char)*100); sprintf($$.code,"\ngo to %s",$$.tr);brlb = $$.fal;swlb = $$.tr;swfal = $$.fal;fprintf(fp,"%s",$$.code);} T_PAOP variable {SYMNODE *new = lookup(var,slist,list); if(new == NULL){printf("Varible not defined");yyerror("");exit(0);}} T_PACL T_CBOP{addNode(list,1);} cases  T_CBCL 	{fprintf(fp,"\n%s:\n",swfal);lbflag = 0;addNode(list,0);}		
;

variable
	: T_ID index			{$$.addr = strdup($1.v);var = $$.addr;}//{$$.addr = (char*)malloc(sizeof(char)*250); sprintf($$.code,"%s%s",$1.v,$2.code);var = $$.addr;}		//FINISHHH
;

index
	: T_SQOP T_INT T_SQCL index		{$$.code = (char*)malloc(sizeof(char)*200);sprintf($$.code,"%s%s%s%s",$1.v,$2.v,$3.v,$4.code);}		//FINISHHH
	|								{$$.code = strdup("");}			//FINISHHHH
;

cases 
	: T_CASELABEL switchconstant T_CLN {$$.tr = newLabel(&ln);fprintf(fp,"\n%s:",$$.tr);cslb[i] = $$.tr;i++;}insidecase cases {if(lbflag == 0 ){lbflag = 1;fprintf(fp,"\n%s:",swlb);}$$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code,"\nif %s = %s go to %s\n",var,$2.code,cslb[--i]);fprintf(fp,"%s",$$.code);}
	|
;

insidecase
	: {addNode(list,1);}singlestatement 		{$$.code = $1.code;addNode(list,0);}
	| block 				{$$.code = $1.code;}
	|
;

switchconstant
	: T_INT				{$$.code = strdup($1.v);}
	| T_STRING			{$$.code = strdup($1.v);}
	| boolean			{$$.code = strdup($1.addr);}
;


while
	: T_WHILE T_PAOP logic_expr T_PACL {$$.tr = newLabel(&ln);wltr = $$.tr;$3.tr = newLabel(&ln);$3.fal = newLabel(&ln);$$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code, "if %s go to %s else go to %s\n%s",$3.addr,$3.tr,$3.fal,$3.tr);fprintf(fp,"%s",$$.code);brlb = $3.fal;contlb = $$.tr;} block {fprintf(fp,"go to %s\n%s:",wltr,$3.fal);}; 
	| T_WHILE T_PAOP logic_expr T_PACL {$$.tr = newLabel(&ln);wltr = $$.tr;$3.tr = newLabel(&ln);$3.fal = newLabel(&ln);$$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code, "if %s go to %s else go to %s\n%s",$3.addr,$3.tr,$3.fal,$3.tr);fprintf(fp,"%s",$$.code);brlb = $3.fal;contlb = $$.tr;} {addNode(list,1);}singlestatement {fprintf(fp,"go to %s\n%s:",wltr,$3.fal);addNode(list,0);}; 
	| T_WHILE T_PAOP logic_expr T_PACL {$$.tr = newLabel(&ln);wltr = $$.tr;$3.tr = newLabel(&ln);$3.fal = newLabel(&ln);$$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code, "if %s go to %s else go to %s\n%s",$3.addr,$3.tr,$3.fal,$3.tr);fprintf(fp,"%s",$$.code);brlb = $3.fal;contlb = $$.tr;} T_SCLN {fprintf(fp,"go to %s\n%s:",wltr,$3.fal);}; 
;

if
	: ifstmt block restofif 		
	| ifstmt {addNode(list,1);}singlestatement {addNode(list,0);} restofif  		

ifstmt 
	: T_IF T_PAOP logic_expr T_PACL {$3.tr = newLabel(&ln); $3.fal = newLabel(&ln);$$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code,"if %s go to %s else goto %s\n%s:",$3.addr,$3.tr,$3.fal,$3.tr);printf("%s",$$.code);$$.next = $3.fal;}
;

restofif
	: {$$.tr = $-1.next;printf("\n%s:",$-1.next);}elseif else 							
;

elseif
	: T_ELIF T_PAOP logic_expr T_PACL {$3.tr = newLabel(&ln); $3.fal = newLabel(&ln);$$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code,"if %s go to %s else goto %s\n%s:",$3.addr,$3.tr,$3.fal,$3.tr);printf("%s",$$.code);$$.next = $3.fal;} block  {printf("\n%s:",$3.fal);} elseif
	| T_ELIF T_PAOP logic_expr T_PACL {$3.tr = newLabel(&ln); $3.fal = newLabel(&ln);$$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code,"if %s go to %s else goto %s\n%s:",$3.addr,$3.tr,$3.fal,$3.tr);printf("%s",$$.code);$$.next = $3.fal;} {addNode(list,1);}singlestatement {addNode(list,0);printf("%s:",$3.fal);} elseif 
	|															//{$$.code = "";}  //FINISHHH
;

else
	: T_ELSE block 												{$$.next = newLabel(&ln);printf("\n%s:",$$.next);} 
	| T_ELSE {addNode(list,1);}singlestatement 									{$$.next = newLabel(&ln);printf("\n%s:",$$.next);addNode(list,0);} 
;

logic_expr
	: rel_expr 						{$$.code = $1.code;$$.addr = $1.addr;}
	| rel_expr logic_op logic_expr  {$$.addr = newTemp(&tn); $$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code,"%s = %s %s %s\n",$$.addr,$1.addr,$2.code,$3.addr);fprintf(fp,"%s",$$.code);}
;

logic_op
	: T_LOGOR 			{$$.code = strdup($1.v);}
	| T_LOGAND			{$$.code = strdup($1.v);}
	| T_LOGXOR			{$$.code = strdup($1.v);}
;


rel_expr
	: T_NOT T_PAOP rel_operand rel_op rel_operand T_PACL
	| rel_operand rel_op rel_operand	{$$.addr = newTemp(&tn); $$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code,"%s = %s %s %s\n",$$.addr,$1.addr,$2.code,$3.addr);fprintf(fp,"%s",$$.code);}
	| rel_operand						{$$.addr = $1.addr;}
;

rel_op
	: T_GREQ	{$$.code = strdup($1.v);}
	| T_LEEQ	{$$.code = strdup($1.v);}
	| T_GR		{$$.code = strdup($1.v);}
	| T_LE 		{$$.code = strdup($1.v);}
	| T_EQCH 	{$$.code = strdup("=");}
;

rel_operand
	: variable		{$$.addr = $1.addr; $$.code = strdup(" ");SYMNODE *new = lookup(var,slist,list); if(new == NULL){printf("%s : Varible not defined",var);yyerror("");exit(0);}}
	| rel_arith_expr {$$.addr = $1.addr; $$.code = strdup(" ");}
	| boolean 		{$$.addr = $1.addr; $$.code = strdup(" ");}
;

boolean
	: T_TRUE		{$$.addr = strdup("TRUE");}
	| T_FALSE		{$$.addr = strdup("FALSE");}
;

assignment
	: variable assign_op arith_expr T_SCLN 		{if(!strcmp($2.code,"=")){$$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code,"%s = %s",$1.addr,$3.addr);if(!strcmp($3.type,"int")){char temp[50];sprintf(temp,"%d",$3.i);addVar($1.addr,temp,$3.type,list->head->scope,list->head->occur,slist);}else{char temp[50];sprintf(temp,"%f",$3.f);addVar($1.addr,temp,$3.type,list->head->scope,list->head->occur,slist);}}else{$$.addr = newTemp(&tn); $$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code,"%s = %s %s %s\n%s = %s",$$.addr,$1.addr,$2.code,$3.addr,$1.addr,$$.addr);fprintf(fp,"\n%s",$$.code);}fprintf(fp,"\n%s",$$.code);if(!strcmp($2.code,"+")){}else if(!strcmp($2.code,"-")){}else if(!strcmp($2.code,"/")){}else if(!strcmp($2.code,"*")){}}
	| variable T_EQUALS T_STRING T_SCLN 		{$$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code,"%s = %s",$1.addr,$3.v);fprintf(fp,"\n%s",$$.code);char *ty = strdup("string");addVar($1.addr,$3.v,ty,list->head->scope,list->head->occur,slist);}
	| prefix_op variable {SYMNODE *new = lookup(var,slist,list); if(new == NULL){printf("%s : Varible not defined",var);yyerror("");exit(0);}} T_SCLN 				{$$.addr = newTemp(&tn); $$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code,"%s = %s %s 1\n%s = %s",$$.addr,$2.addr,$1.code,$2.addr,$$.addr);fprintf(fp,"\n%s",$$.code);SYMNODE *new = lookup(var,slist,list);if(!strcmp($1.code,"+")){char temp[50];sprintf(temp,"%d",atoi(new->val)+1);addVar(var,temp,new->type,new->scope,new->occur,slist);}else{char temp[50];sprintf(temp,"%d",atoi(new->val)-1);addVar(var,temp,new->type,new->scope,new->occur,slist);}}
	| variable {SYMNODE *new = lookup(var,slist,list); if(new == NULL){printf("%s : Varible not defined",var);yyerror("");exit(0);}} postfix_op T_SCLN 				{$$.addr = newTemp(&tn); $$.code = (char*)malloc(sizeof(char)*100);sprintf($$.code,"%s = %s %s 1\n%s = %s",$$.addr,$1.addr,$2.code,$1.addr,$$.addr);fprintf(fp,"\n%s",$$.code);SYMNODE *new = lookup(var,slist,list);if(!strcmp($2.code,"+")){char temp[50];sprintf(temp,"%d",atoi(new->val)+1);addVar(var,temp,new->type,new->scope,new->occur,slist);}else{char temp[50];sprintf(temp,"%d",atoi(new->val)-1);addVar(var,temp,new->type,new->scope,new->occur,slist);}}
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
	: T_INC				{$$.code = strdup("+");}
	| T_DEC 			{$$.code = strdup("-");}
;

postfix_op
	: T_INC 			{$$.code = strdup("+");}
	| T_DEC 			{$$.code = strdup("-");}
;


rel_arith_expr
	: rel_arith_expr T_PLUS rel_term 	{$$.addr = newTemp(&tn);$$.code = (char*)malloc(sizeof(char)*100); sprintf($$.code,"\n%s = %s + %s",$$.addr,$1.addr,$3.addr);fprintf(fp,"%s",$$.code);}
	| rel_arith_expr T_MINUS rel_term 	{$$.addr = newTemp(&tn);$$.code = (char*)malloc(sizeof(char)*100); sprintf($$.code,"\n%s = %s - %s",$$.addr,$1.addr,$3.addr);fprintf(fp,"%s",$$.code);}
	| rel_term							{$$.addr = $1.addr;$$.code = $1.code;}
;

rel_term
	: rel_term T_MUL rel_factor 		{$$.addr = newTemp(&tn);$$.code = (char*)malloc(sizeof(char)*100); sprintf($$.code,"\n%s = %s * %s",$$.addr,$1.addr,$3.addr);fprintf(fp,"%s",$$.code);}
	| rel_term T_DIVIDE rel_factor 		{$$.addr = newTemp(&tn);$$.code = (char*)malloc(sizeof(char)*100); sprintf($$.code,"\n%s = %s / %s",$$.addr,$1.addr,$3.addr);fprintf(fp,"%s",$$.code);}
	| rel_term T_MOD rel_factor 		{$$.addr = newTemp(&tn);$$.code = (char*)malloc(sizeof(char)*100); sprintf($$.code,"\n%s = %s mod %s",$$.addr,$1.addr,$3.addr);fprintf(fp,"%s",$$.code);}
	| rel_factor 						{$$.addr = $1.addr;$$.code = $1.code;}
;


rel_factor
	: rel_const 						{$$.addr = $1.addr;$$.code = $1.code;}
	| T_PAOP rel_arith_expr T_PACL 		{$$.addr = $2.addr;$$.code = $2.code;}

;

rel_const
	: T_INT								{$$.addr = strdup($1.v); $$.code = strdup("");}
	| T_FLOAT 							{$$.addr = strdup($1.v); $$.code = strdup("");}						
	| T_STRING 							{$$.addr = strdup($1.v); $$.code = strdup("");}
;

arith_expr
	: arith_expr T_PLUS term 					{$$.addr = newTemp(&tn);$$.code = (char*)malloc(sizeof(char)*100); sprintf($$.code,"\n%s = %s + %s",$$.addr,$1.addr,$3.addr);fprintf(fp,"%s",$$.code);if(!strcmp($1.type,"int")){$$.type = $1.type;$$.i = $1.i + $3.i; }else{$$.type = $1.type;$$.f = $1.f + $3.f;}}
	| arith_expr T_MINUS term 					{$$.addr = newTemp(&tn);$$.code = (char*)malloc(sizeof(char)*100); sprintf($$.code,"\n%s = %s - %s",$$.addr,$1.addr,$3.addr);fprintf(fp,"%s",$$.code);if(!strcmp($1.type,"int")){$$.type = $1.type;$$.i = $1.i - $3.i;}else{$$.type = $1.type;$$.f = $1.f - $3.f;}}
	| term 										{$$.addr = $1.addr;$$.code = $1.code;if(!strcmp($1.type,"int")){$$.type = $1.type;$$.i = $1.i;}else{$$.type = $1.type;$$.f = $1.f;}}
;

term
	: term T_MUL factor 						{$$.addr = newTemp(&tn);$$.code = (char*)malloc(sizeof(char)*100); sprintf($$.code,"\n%s = %s * %s",$$.addr,$1.addr,$3.addr);fprintf(fp,"%s",$$.code);if(!strcmp($1.type,"int")){$$.type = $1.type;$$.i = $1.i * $3.i;}else{$$.type = $1.type;$$.f = $1.f*$1.f;}}
	| term T_DIVIDE factor 						{$$.addr = newTemp(&tn);$$.code = (char*)malloc(sizeof(char)*100); sprintf($$.code,"\n%s = %s / %s",$$.addr,$1.addr,$3.addr);fprintf(fp,"%s",$$.code);if(!strcmp($1.type,"int")){$$.type = $1.type;$$.i = $1.i / $3.i;}else{$$.type = $1.type;$$.f = $1.f / $3.f;}}
	| term T_MOD factor 						{$$.addr = newTemp(&tn);$$.code = (char*)malloc(sizeof(char)*100); sprintf($$.code,"\n%s = %s mod %s",$$.addr,$1.addr,$3.addr);fprintf(fp,"%s",$$.code);if(!strcmp($1.type,"int")){$$.type = $1.type;$$.i = $1.i % $3.i;}else{printf("\nMod not allowed for floats");}}
	| factor 									{$$.addr = $1.addr;$$.code = $1.code;if(!strcmp($1.type,"int")){$$.type = $1.type;$$.i = $1.i;}else{$$.type = $1.type;$$.f = $1.f;}}
;


factor
	: const 							{$$.addr = $1.addr;$$.code = $1.code;if(!strcmp($1.type,"int")){$$.type = $1.type;$$.i = $1.i;}else{$$.type = $1.type;$$.f = $1.f;}}
	| T_PAOP arith_expr T_PACL 			{$$.addr = $2.addr;$$.code = $2.code;if(!strcmp($2.type,"int")){$$.type = $2.type;$$.i = $2.i;}else{$$.type = $2.type;$$.f = $2.f;}}
	| variable 							{SYMNODE *new = lookup(var,slist,list);$$.addr = $1.addr;$$.code = strdup("");if(new == NULL){printf("%s not defined",var);yyerror("");}if(!strcmp(new->type,"int")){$$.type = strdup("int");$$.i = atoi(new->val);}else{$$.type = strdup("float");$$.f = atof(new->val);}}

;

const
	: T_INT				{$$.addr = strdup($1.v); $$.code = strdup("");$$.type = strdup("int");$$.i = atoi($1.v);}
	| T_FLOAT			{$$.addr = strdup($1.v); $$.code = strdup("");$$.type = strdup("float");$$.f = atof($1.v);}
;

assign_op
	: T_EQUALS			{$$.code = strdup($1.v);}
	| T_ADDEQ			{$$.code = strdup("+");}
	| T_SUBEQ			{$$.code = strdup("-");}
	| T_MULEQ			{$$.code = strdup("*");}
	| T_DIVEQ			{$$.code = strdup("/");}
;



block
	: T_CBOP{addNode(list,1);} statement T_CBCL					{$$.code = $1.code;addNode(list,0);}
;

break
	: T_BRK T_SCLN 								{$$.code = (char*)malloc(sizeof(char)*100); sprintf($$.code,"\ngo to %s",brlb);printf("%s",$$.code);}
;

continue
	: T_CNTUE T_SCLN 							{$$.code = (char*)malloc(sizeof(char)*100); sprintf($$.code,"\ngo to %s",contlb);printf("%s",$$.code);}
;


%%
// if-else can switches be an empty block? switchconstant can't have empty singlestatement T_STRING strings default case
char* newLabel(int *ln)
{
	char *s = (char*)malloc(4*sizeof(char));
	sprintf(s,"L%d",*ln);
	//printf("%s",s);
	(*ln)++;
	return s;
}
char* newTemp(int *tn)
{
	char *s = (char*)malloc(4*sizeof(char));
	sprintf(s,"T%d",*tn);
	//printf("%s",s);
	(*tn)++;
	return s;
}
void addNode(DLIST *list,int open)
{
	NODE *temp = (NODE*)malloc(sizeof(NODE));
	temp->next = NULL;
	temp->prev = list->head;
	
	if(open == 1)
	{
		NODE *iter = list->head;
		int flag =0; 
		temp->scope = ++scope;
		while(iter!=NULL)
		{
			if(iter->scope == scope)
			{
				temp->occur = iter->occur+1;
				flag = 1;
			}
			if(flag == 1)
				break;
			iter = iter->prev;
		}
		if(flag == 0)
		{
			temp->occur = 0 ;
		}
	}
	else
	{
		NODE *iter = list->head;
		--scope;
		int flag =0;
		temp->scope = scope;
		while(iter!=NULL)
		{
			if(iter->scope == scope)
			{
				temp->occur = iter->occur;
				flag = 1;
			}
			if(flag ==1 )
				break;
			iter = iter->prev;
		}
		if(flag == 0)
		{
			temp->occur = 0;
		}
	}
	list->head = temp;
}
void printlist(DLIST *list)
{
	NODE *temp = list->head;
	
	while(temp!=NULL)
	{
		printf("\n");
		printf("%d%d<-",temp->scope,temp->occur);
		temp = temp->prev;

	}
}
void addVar(char *name,char *val,char *type,int scope,int occur,SYMLIST *slist)
{
	SYMNODE *temp = (SYMNODE*)malloc(sizeof(SYMNODE));
	temp->next = NULL;
	temp->prev = slist->head;
	temp->name = strdup(name);
	temp->type = strdup(type);
	temp->val = strdup(val);
	temp->scope = scope;
	temp->occur = occur;
	slist->head = temp;
}
void printsym(SYMLIST *slist)
{
	SYMNODE *temp = slist->head;
	while(temp!= NULL)
	{
		printf("\n");
		printf("%s,%s,%s,%d%d<-\n",temp->name,temp->val,temp->type,temp->scope,temp->occur);
		temp = temp->prev;
	}
}
SYMNODE* varsearch(char *name,SYMNODE *stemp,NODE *temp)
{
	SYMNODE *iter = stemp;
	while(iter!=NULL)
	{
		if(!strcmp(name,iter->name) && iter->scope == temp->scope && iter->occur == temp->occur)
			return iter;
		iter = iter->prev;
	}
	return NULL;
}
SYMNODE* lookup(char *name,SYMLIST *slist, DLIST *list)
{
	NODE *temp = list->head;
	SYMNODE *stemp = slist->head;
	int errflag = 0;
	while(errflag == 0 )
	{
		SYMNODE* res = varsearch(name,stemp,temp);
		if(res != NULL)
			return res;
		if(temp->scope == 0)
		{
			errflag = 1;
			return NULL;
		}
		else
		{
			NODE *iter = temp;
			while(iter->scope!=temp->scope-1)
				iter = iter->prev;
			temp = iter;
		}
	}
}
int main(int argc, char* argv[])
{
/*TABLE *s=(TABLE*)malloc(sizeof(TABLE));
	s->head = NULL;
	s->entries = 0;*/
	yyin = fopen(argv[1], "r");
	fp = stdout;
	int flag = 1;
	if(!yyparse())
			{printf("Parsing successful \n");flag = 0;}
		else
			{printf("Unsuccessful \n");}
	return flag;
}
