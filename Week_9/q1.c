#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node* NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}
void display(NODE first)
{
    NODE cur;
    cur=first;
    if(first==NULL)
    {
        printf("Empty\n");
        return;
    }
    printf("Contents are:\n");
    while(cur!=NULL)
    {
        printf("%d\t",cur->data);
        cur=cur->link;
    }
    printf("\n");
}
NODE insert(int ele,NODE first)
{
    NODE cur,temp;
    temp=getnode();
    temp->data=ele;
    temp->link=NULL;
    if(first==NULL)
        return temp;
    cur=first;
    while(cur->link!=NULL)
        cur=cur->link;
    cur->link=temp;
    return first;
}
NODE delete(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Empty!!");
        return NULL;
    }
    temp=first;
    temp=temp->link;
    printf("Deleted %d\n",first->data);
    free(first);
    return temp;
}
void main()
{
    NODE first;
    int choice,ele;
    first=NULL;
    while(1)
    {
        printf("Enter 1)Insert 2)Delete 3)Display 4)Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter element:");
            scanf("%d",&ele);
            first=insert(ele,first);
            break;
        case 2:
            first=delete(first);
            break;
        case 3:
            display(first);
            break;
        case 4:
            exit(0);
        }
    }
}
