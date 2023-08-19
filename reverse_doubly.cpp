#include<stdio.h>
#include<stdlib.h>
struct node
{
	
	struct node *prev;
	int data;
	struct node *next;
};
struct node * createlist(struct node*start,int n)
{
	int i;
	struct node *tmp;
	for(i=1;i<=n;i++)
	{
		struct node *current=(struct node*)malloc(sizeof(struct node));
		if(current==NULL)
		printf("memory cannot be allocated\n");
			scanf("%d",&current->data);
			current->prev=NULL;
			current->next=NULL;
			if(i==1)
			tmp=start=current;
			else
			{
				current->prev=tmp;
				tmp->next=current;
				tmp=current;
			}			
	}
	return start;
}
void print(struct node *start)
{
	struct node *p=start;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
struct node * rev(struct node *start)
{
	struct node * p1,*p2;
	p1=start;
	p2=start->next;
	
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
	p2->prev=p2->next;
	p2->next=p1;
	p1=p2;
	p2=p2->prev;
	}
	start=p1;
	return start;
	
}
int main()
{
	int n,pos;
	struct node *start;
	printf("enter number of element in list\n");
	scanf("%d",&n);
	if(n==0)
	{
		printf("list cannot be created with no element\n");
		exit(0);
	}
	
	printf(" enter list\n");
	start=createlist(start,n);
	
	printf("\n list is\n");
	print(start);
	
	printf("\nreverse is\n");
	start=rev(start);
	print(start);
}
