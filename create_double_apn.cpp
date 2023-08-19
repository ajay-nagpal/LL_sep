#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*start,*temp;
struct node * create(struct node *start,int n)
{
	int i;
	if(n==0)
	{
		printf("empty list\n");
		exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		struct node *current=(struct node *)malloc(sizeof(struct node));
		if(current==NULL)
		printf("memory cannot be allocated\n");
		else
		{
		scanf("%d",&current->data);
		current->prev=NULL;
		current->next=NULL;
			if(i==1)
			temp=start=current;
			else
			{
			temp->next=current;
			current->prev=temp;
			temp=current;	
			}	
		}
		
	}
	return start;
}
void print(struct node * start)
{
	struct node *p=start;
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
}
void addafter(struct node*start ,int el,int nel)
{
	struct node *current=(struct node *)malloc(sizeof(struct node));
	current->data=nel;
	current->prev=NULL;
	current->next=NULL;
	
	struct node *p=start;
	while(p!=NULL)
	{
		if(p->data==el)
		{
			current->prev=p;
			current->next=p->next;
			if(p->next!=NULL)
			p->next->prev=current;
			p->next=current;
		}
		p=p->next;
	}
}

struct node* addbefore(struct node*start ,int el,int nel)
{
	struct node *current=(struct node *)malloc(sizeof(struct node));
	current->data=nel;
	current->prev=NULL;
	current->next=NULL;
	
	if(start->data==el)
	{
		current->next=start;
		start->prev=current;
		start=current;
		return start;
	}
	
	struct node *p=start;
	while(p!=NULL)
	{
		if(p->data==el)
		{
			p->prev->next=current;
			current->prev=p->prev;
			current->next=p;
			p->prev=current;
		}
		p=p->next;
	}
	return start;
}
int main()
{
	int n;
	start=NULL;
	printf("enter no of element in list\n");
	scanf("%d",&n);
	
	printf("enter list\n");
	start=create(start,n);
	printf("list is\n");
	print(start);
	
	int el,nel;
	printf("\nenter element aftr which you want to enter new element\n");
	scanf("%d",&el);
	printf("enter  new element\n");
	scanf("%d",&nel);	
	
	addafter(start,el,nel);
	print(start);
	
	printf("\nenter element before which you want to enter new element\n");
	scanf("%d",&el);
	printf("enter  new element\n");
	scanf("%d",&nel);	
	
	start=addbefore(start,el,nel);
	print(start);		
}
	
