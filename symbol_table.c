void insert(char* name, int value, char* type) 
{ 
	/*if(exists(name))
	{
		printf("Variable %s already declared",name);
		return;
	}
    NODE* test = (NODE*) malloc(sizeof(NODE)); 
    strcpy(test->name,name);
	test->value=value;
	test->next=NULL ;
	test->scope=scope;
	strcpy(test->type, type);
	NODE* temp;
	if(s->head == NULL)
	{
		s->head = test;
		return;
	}
	while(temp -> next != NULL)
	{
		temp = temp->next;
	}
	temp->next = test;
	s->entries+=1;
	print();
	*/
}

int exists(char* name)
{
	/*NODE* temp = s->head;
	if(s->head == NULL)
		return 0;
	while(temp != NULL)
	{
		if(strcmp(temp->name,name) == 0)
			return 1;
		temp = temp->next;
	}
	return 0;*/
	return 1;
}

void update(char* name, int val)
{
	NODE* temp = s->head;
	while(temp != NULL)
	{
		if(strcmp(temp->name,name) == 0){
			temp->value = val;
		}
		temp = temp->next;
	}
	print();
}

void funcend()
{
	/*scopered(0);
	printf("done");
	if(s->head == NULL)
		free(s);*/
}

void scopered(int scope)
{
	/*if(s->head == NULL)
		return;
	NODE* temp = s->head;
	NODE* temp1 = s->head->next;
	if(temp->scope == scope)
	{
		s->head = NULL;
	}
	while(temp1 != NULL)
	{
		if(temp1->scope == scope){
			temp->next = NULL;
			temp = temp1;
			temp1 = temp1->next;
		}
	}
	while(temp1 != NULL)
	{
		free(temp);
		temp = temp1;
		temp1 = temp1 -> next;
	}
	free(temp);*/
}

void print()
{
	NODE* h = s->head;
	printf("\nSymbol table \nName  Value  Type  Scope\n");
	for(int i=0;i<s->entries; i++ )
	{
		printf("%s  %d  %s  %d\n", h->name, h->value, h->type, h->scope);
		h=h->next;
	}
printf("\n\n");
}
