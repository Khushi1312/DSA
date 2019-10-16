struct node
{
	int exp;
	struct node*next;
	int coef;
};

void insert(struct node**head,int exp,int coef)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->exp=exp;
	temp->coef=coef;
	if(*head==NULL)
	{
		*head=(struct node*)malloc(sizeof(struct node));
		temp->next=*head;
		(*head)->next=temp;
	}

	else
	{
		struct node*temp2;
		temp2=(*head)->next;
		while(temp2->next!=*head)
			temp2=temp2->next;
		temp->next=*head;
		temp2->next=temp;
	}

}

void printlist(struct node*head)
{
	struct node*temp=head->next;

	do
	{
		printf("%d  ",temp->exp);
		temp=temp->next;
	}
	while(head!=temp);
}