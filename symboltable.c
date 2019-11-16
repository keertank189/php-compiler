#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct symnode{
	char *name;
	char *val;
	char *type;
	int scope;
	int occur;
	struct symnode *prev;
	struct symnode *next;
}SYMNODE;
typedef struct symlist{
	SYMNODE* head;
}SYMLIST;
void addVar(char *name,char *val,char *type,int scope,int occur,SYMLIST *slist)
{
	SYMNODE *temp = (SYMNODE*)malloc(sizeof(SYMNODE));
	temp->next = NULL;
	temp->prev = slist->head;
	temp->name= name;
	temp->type = type;
	temp->val = val;
	temp->scope = scope;
	temp->occur = occur;
	slist->head = temp;
}
void printsym(SYMLIST *slist)
{
	SYMNODE *temp = slist->head;
	while(temp!= NULL)
	{
		printf("%s,%s,%s,%d%d<-",temp->name,temp->val,temp->type,temp->scope,temp->occur);
		temp = temp->prev;
	}
}
SYMNODE* varsearch(char *name,SYMNODE *stemp,NODE *temp)
{
	SYMNODE *iter = stemp;
	while(iter!=NULL)
	{
		if(!strcmp(name,iter->name) && iter->scope == temp->scope && iter->occur = temp->occur)
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
				iter = iter->prev
			temp = iter;
		}
	}
}
int main()
{
	SYMLIST *slist = (SYMLIST*)malloc(sizeof(SYMLIST));
	slist->head = NULL;
	addVar("x","hello","string",1,2,slist);
	addVar("y","234","int",0,0,slist);
	addVar("x","4.4","float",1,0,slist);
	printsym(slist);
}