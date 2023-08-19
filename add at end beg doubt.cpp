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
struct node * addatbeg(struct node *start,int data)
{
	struct node* tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=data;
	tmp->prev=NULL;
	tmp->next=start;
	start->prev=tmp;
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
	int data;
	struct node *start;
	start=NULL;
	
	printf("enter data to add in empty list\n");
	scanf("%d",&data);
	start=addinempty(start,data);
	
	
	printf("enter data to add at beg of 1st node\n");
	scanf("%d",&data);
	start=addatbeg(start,data);	
	
	printf("enter data to add at end of list\n");
	scanf("%d",&data);
	addatend(start,data);
	
	printf("list is\n");
	print(start);
}
