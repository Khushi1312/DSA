#include<stdio.h>
#include<stdlib.h>
#include"circularlinkedlist.h"

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

struct node*add(struct node*a,struct node*b)
{
	struct node*sum=NULL;
	struct node*pa=a;
	struct node*pb=b;

	a=a->next;
	b=b->next;

	while(pa!=a && pb!=b)
	{
		if(a->exp>b->exp)
		{
			insert(&sum,a->exp,a->coef);
			a=a->next;
		}

		else if(a->exp<b->exp)
		{
			insert(&sum,b->exp,b->coef);
			b=b->next;
		}

		else
		{
			insert(&sum,a->exp,(a->coef+b->coef));
			a=a->next;
			b=b->next;
		}
	}

	if(a==pa)
	{
		while(pb!=b)
		{
			insert(&sum,b->exp,b->coef);
			b=b->next;
		}
	}

	else
	{
		while(pa!=a)
		{
			insert(&sum,a->exp,a->coef);
			a=a->next;
		}

	}

	return(sum);


}


struct node*subtract(struct node*a,struct node*b)
{
	struct node*sum=NULL;
	struct node*pa=a;
	struct node*pb=b;

	a=a->next;
	b=b->next;

	while(pa!=a && pb!=b)
	{
		if(a->exp>b->exp)
		{
			insert(&sum,a->exp,a->coef);
			a=a->next;
		}

		else if(a->exp<b->exp)
		{
			insert(&sum,b->exp,-(b->coef));
			b=b->next;
		}

		else
		{
			insert(&sum,a->exp,(a->coef-b->coef));
			a=a->next;
			b=b->next;
		}
	}

	if(a==pa)
	{
		while(pb!=b)
		{
			insert(&sum,b->exp,-(b->coef));
			b=b->next;
		}
	}

	else
	{
		while(pa!=a)
		{
			insert(&sum,a->exp,a->coef);
			a=a->next;
		}

	}

	return(sum);


}

int main()
{
	struct node*a=NULL;
	struct node*b=NULL;

	printf("Enter first polynomial\n");
	int br=0,exp,coef;

	while(br==0)
	{
		printf("Enter exponent\n");
		scanf("%d",&exp);
		printf("Enter Coefficient\n");
		scanf("%d",&coef);

		insert(&a,exp,coef);

		printf("Done???\n(1/0)\n");
		scanf("%d",&br);
	}

	printf("Enter second polynomial\n");
	br=0;
	while(br==0)
	{
		printf("Enter exponent\n");
		scanf("%d",&exp);
		printf("Enter Coefficient\n");
		scanf("%d",&coef);

		insert(&b,exp,coef);

		printf("Done???\n(1/0)\n");
		scanf("%d",&br);
	}

	struct node*sum=add(a,b);

	printf("Sum:\n");

	for(struct node*i=sum->next;i!=sum;i=i->next)
	{
		printf("Coefficient: %d \nExponent: %d\n",i->coef,i->exp);
	}

	struct node*diff = subtract(a,b);

	printf("\n-----------------");
	printf("Difference:\n");

	for(struct node*i=diff->next;i!=diff;i=i->next)
	{
		printf("Coefficient: %d \nExponent: %d\n",i->coef,i->exp);
	}

	struct node*mul[length(b)];

	for(int i=0;i<length(b);i++)
		mul[i]=NULL;

	int i2=0;

	for(struct node*i=b->next;i!=b;i=i->next)
	{
		for(struct node*i1=a->next;i1!=a;i1=i1->next)
		{

			insert(&mul[i2],i1->exp+i->exp,i1->coef * i->coef);

		}
		i2++;
	}

	for(int i=0;i<length(b)-1;i++)
	{
		mul[i+1]=add(mul[i],mul[i+1]);
	}
	printf("\n-----------------");

	printf("Multiplication:\n");

	for(struct node*i=mul[length(b)-1]->next;i!=mul[length(b)-1];i=i->next)
	{
		printf("Coefficient: %d \nExponent: %d\n",i->coef,i->exp);
	}

exit(0);


}