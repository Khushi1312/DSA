#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
}  ;
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
    if(first==NULL)
    {
        printf("Empty!\n");
        return;
    }
    printf("Contents are:\n");
    cur=first;
    while(cur!=NULL)
    {
        printf("%d ",cur->info);
        cur=cur->link;
    }
    printf("\n");
}

NODE insert_r(int item,NODE first)
{
    NODE cur,temp;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)
        return temp;
    cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}

int search(int key,NODE first)
{
    NODE cur;
    if(first==NULL)
        return 0;
    cur=first;
    while(cur!=NULL)
    {
        if(key==cur->info)
            return 1;
        cur=cur->link;
    }
    return 0;
}

NODE unionn(NODE first,NODE second)
{
    NODE a,third;
    a=first;
    third=NULL;
    while(a!=NULL)
    {
        third=insert_r(a->info,third);
        a=a->link;
    }
    a=second;
    while(a!=NULL)
    {
        if(search(a->info,third)==0)
            third=insert_r(a->info,third);
        a=a->link;
    }
    return third;
}
NODE intersection(NODE first,NODE second)
{
    NODE a,b,third;
    a=first;
    third=NULL;
    while(a!=NULL)
    {
        if(search(a->info,second)==1)
            third=insert_r(a->info,third);
        a=a->link;
    }
    return third;
}
void main()
{
    NODE first,second,third;
    int choice,ele,n,i;
    printf("Enter 1)create 1st 2)create 2nd 3)UNION 4)INTERSECTION 5)EXIT\n");
    for(;;)
    {
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter no of nodes in 1st list:");
            scanf("%d",&n);
            first=NULL;
            printf("Enter elements:");
            for(i=0;i<n;i++)
            {
                scanf("%d",&ele);
                first=insert_r(ele,first);
            }
            break;
        case 2:
            printf("Enter no of nodes in 2nd list:");
            scanf("%d",&n);
            second=NULL;
            printf("Enter elements:");
            for(i=0;i<n;i++)
            {
                scanf("%d",&ele);
                second=insert_r(ele,second);
            }
            break;
        case 3:
            printf("first is:\n");
            display(first);
            printf("second is:\n");
            display(second);
            third=unionn(first,second);
            printf("Union is:\n");
            display(third);
            break;
        case 4:
            printf("first is:\n");
            display(first);
            printf("second is:\n");
            display(second);
            third=intersection(first,second);
            printf("Intersection is:\n");
            display(third);
            break;
        case 5:
            exit(0);
        }
    }
}