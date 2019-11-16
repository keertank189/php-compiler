#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	struct node *prev;
	struct node *next;
	int scope;
	int occur;
}NODE;
int scope = 0,occur = 0;
typedef struct dllist
{
	NODE *head;
	int no;
}DLIST;
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
		printf("%d%d<-",temp->scope,temp->occur);
		temp = temp->prev;
	}
}

int main()
{
	char *str = strdup("{{}{{}{}}}");
	DLIST *list = (DLIST*)malloc(sizeof(DLIST));
	NODE *first = (NODE*)malloc(sizeof(NODE));
	first->prev = NULL;
	first->next = NULL;
	first->scope = scope;
	first->occur = occur;
	list->head = first;
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i] == '{')
		{
			addNode(list,1);
		}
		else if(str[i] == '}')
		{
			addNode(list,0);
		}
	}
	printlist(list);
}