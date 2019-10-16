struct node
{
	struct node* prev;
	int data;
	struct node*next;

};


void makecircular(struct node**head,int ele)
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	if(*head==NULL)
	{
		*head=(struct node*)malloc(sizeof(struct node));
		(*head)->next=temp;
		temp->next=*head;
		temp->prev=*head;
		temp->data=ele;
		(*head)->prev=temp;
	}

	else
	{
		struct node*last;
		last=(*head)->next;
		while(last->next!=*head)
		{
			last=last->next;
		}
		temp->data=ele;
		temp->next=*head;
		temp->prev=last;
		last->next=temp;
		(*head)->prev=temp;

	}

}