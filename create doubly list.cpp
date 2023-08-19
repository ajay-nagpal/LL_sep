#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node * addinempty(struct node* start,int data)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
}

void addatend(struct node*start,int data)
{
	struct node* tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=data;
	struct node *p;
	p=start;
	while(p->next!=NULL)
	p=p->next;
		
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;

}
void print(struct node*start)
{
	struct node *p=start;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
int main()
{
	int data,n,i;
	struct node *start;
	start=NULL;
	printf("enter no of elememtn in list\n");
	scanf("%d",&n);
;	if(n==0)
	{
		printf("empty list\n");
		return 0;
	}
	printf("enter data to add \n");
	scanf("%d",&data);
	start=addinempty(start,data);
	
	for(i=2;i<=n;i++)
	{
	printf("enter data to add at end of list\n");
	scanf("%d",&data);
	addatend(start,data);
	}
	
	printf("list is\n");
	print(start);
}
