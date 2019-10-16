#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"doubllylinkedlist.h"

int length(struct node*head)
{
	struct node*t=head->next;
	int l=0;

	while(t!=head)
	{
		l++;
		t=t->next;
	}

	return l;
}

struct node* add(struct node*a, struct node*b)
{
	struct node*pa=a;
	struct node*pb=b;

	a=a->prev;
	b=b->prev;

	int carry=0;
	int psum;

	struct node*sum=NULL;

	while(a!=pa && b!=pb)
	{
		psum=a->data+b->data+carry;
		makecircular(&sum,psum%10);
		carry=psum/10;
		a=a->prev;
		b=b->prev;
	}
	psum=a->data+b->data+carry;
	makecircular(&sum,psum%10);
	carry=psum/10;
	a=a->prev;
	b=b->prev;


	if(length(a)<length(b))
	{

		while(b!=pb)
		{
			psum=carry+b->data;
			makecircular(&sum,psum%10);
			carry=psum/10;
			b=b->prev;
		}
	}


	if(length(a)>length(b))
	{
		while(a!=pa)
		{
			psum=carry+a->data;
			makecircular(&sum,psum%10);
			carry=psum/10;
			a=a->prev;
		}
	}

	return (sum);


}

int main()
{
	struct node*a=NULL;
	struct node*b=NULL;

	printf("Enter first number\n");
	char s[100];
	fgets(s,100,stdin);

	for(int i=0;i<strlen(s)-1;i++)
		makecircular(&a,s[i]-'0');

	printf("Enter second number\n");
	fgets(s,100,stdin);
	for(int i=0;i<strlen(s)-1;i++)
		makecircular(&b,s[i]-'0');

	struct node*sum=add(a,b);

	int arr[100];
	int i=length(sum)-1;

	for(struct node*psum=sum->next;psum!=sum;psum=psum->next)
	{
		arr[i]=psum->data;
		i--;
	}

	for(int i1=0;i1<length(sum);i1++)
	{
		printf("%d",arr[i1]);
	}

	return 0;
}