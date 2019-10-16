#include <stdlib.h>
#include <stdio.h>
struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node* NODE;

NODE getNode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	return x;
}
NODE insert_f(int item,NODE first)
{
	NODE temp;
	temp=getNode();
	temp->info=item;
	temp->llink=temp->rlink=NULL;
	if(first==NULL)
		return temp;
	temp->rlink=first;
	first->llink=temp;
	return temp;
}
NODE insert_r(int item,NODE first) 
{
	NODE cur,temp;
	temp=getNode();
	temp->info=item;
	temp->llink=temp->rlink=NULL;
	if(first==NULL)
		return temp;
	cur=first;
	while(cur->rlink!=NULL)
	{
		cur=cur->rlink;
	}
	cur->rlink=temp;
	temp->llink=cur;
	return first;
}
NODE delete_f(NODE first)
{
	NODE temp;
	if(first==NULL)
	{
		printf("EMPTY!");
		return NULL;
	} 
	if(first->rlink==NULL)
	{
		printf("Deleted: %d\n",first->info);
		free(first);
		return NULL;
	}
	temp=first->rlink;
	temp->llink=NULL;
	printf("Deleted: %d\n",first->info);
	free(first);
	return temp;
}
NODE delete_r(NODE first)
{
	NODE cur,pre;
	if(first==NULL)
	{
		printf("EMPTY!");
		return NULL;
	} 
	if(first->rlink==NULL)
	{
		printf("Deleted: %d\n",first->info);
		free(first);
		return NULL;
	}
	pre=NULL;
	cur=first;
	while(cur->rlink!=NULL)
	{
		pre=cur;
		cur=cur->rlink;
	}
	printf("Deleted: %d\n",cur->info);
	free(cur);
	pre->rlink=NULL;
	return first;
}
void display(NODE first)
{
	NODE cur;
	if(first==NULL)
	{
		printf("EMPTY!");
		return;
	} 
	printf("Contents of doubly ll are:\n");
	cur=first;
	while(cur!=NULL)
	{
		printf("%d ",cur->info);
		cur=cur->rlink;
	}
	printf("\n");
}
void main()
{
	NODE first;
	int choice,item;
	first=NULL;
	printf("Enter 1)insert_r 2)insert_f 3)delete_r 4)delete_f 5)display\n");
	for(;;)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter element to insert:");
			scanf("%d",&item);
			first=insert_r(item,first);
			break;
			case 2:
			printf("Enter element to insert:");
			scanf("%d",&item);
			first=insert_f(item,first);
			break;
			case 3:
			first=delete_r(first);
			break;
			case 4:
			first=delete_f(first);
			break;
			case 5:
			display(first);
			break;
			default:
			exit(0);
		}
	}
}