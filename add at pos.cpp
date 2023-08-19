#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*start,*temp;
int flag=1;
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
	//int flag=1;
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
			flag=0;
		}
		p=p->next;
	}
	if(flag==1)
	{
		printf("no element like this in list\n");
		exit(0);
	}
}

struct node* addbefore(struct node*start ,int el,int nel)
{
	//int flag=1;
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
			flag=0;
		}
		p=p->next;
	}
	if(flag==1)
	{
		printf("no element like this in list\n");
		exit(0);
	}
	return start;
}
struct node* addatpos(struct node *start,int pos,int nel)
{
	//int flag=1;
	struct node *current=(struct node *)malloc(sizeof(struct node));
	current->data=nel;
	current->prev=NULL;
	current->next=NULL;
	
	if(pos==1)
	{
		current->next=start;
		start->prev=current;
		start=current;
		return start;
	}
	int posh=1;
	struct node *p=start;
	while(posh!=pos)
	{
		p=p->next;
		posh++;
	}
	if(posh==pos)
		{
			p->prev->next=current;
			current->prev=p->prev;
			current->next=p;
			p->prev=current;
			flag=0;
		}
	if(flag==1)
	{
		printf("no element like this in list\n");
		exit(0);
	}
	return start;
	
}
struct node* addbeforepos(struct node *start,int pos,int nel)
{
	//int flag=1;
	struct node *current=(struct node *)malloc(sizeof(struct node));
	current->data=nel;
	current->prev=NULL;
	current->next=NULL;
	
	if(pos==1)
	{
		current->next=start;
		start->prev=current;
		start=current;
		return start;
	}
	int posh=1;
	struct node *p=start;
	while(posh!=pos)
	{
		p=p->next;
		posh++;
	}
	if(posh==pos)
		{
			p->prev->next=current;
			current->prev=p->prev;
			current->next=p;
			p->prev=current;
			flag=0;
		}
	if(flag==1)
	{
		printf("no pos like this in list\n");
		exit(0);
	}
	return start;	
}
void addafterpos(struct node *start,int pos,int nel)
{
	//int flag=1;
	struct node *current=(struct node *)malloc(sizeof(struct node));
	current->data=nel;
	current->prev=NULL;
	current->next=NULL;
	
	struct node *p=start;
	int posh=1;
	
	while(posh!=pos)
	{
		p=p->next;
		posh++;
	}
		if(posh==pos)
		{
			current->prev=p;
			current->next=p->next;
			if(p->next!=NULL)
			p->next->prev=current;
			p->next=current;
			flag=0;
		}	
	if(flag==1)
	{
		printf("no pos like this in list\n");
		exit(0);
	}
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
	
	int pos;
	printf("\n enter position you want to add new eleement\n");
	scanf("%d",&pos);
	printf("enter  new element\n");
	scanf("%d",&nel);
	start=addatpos(start,pos,nel);
	print(start);
	
	printf("\n enter position before which you want to add new eleement\n");
	scanf("%d",&pos);
	printf("enter  new element\n");
	scanf("%d",&nel);
	start=addbeforepos(start,pos,nel);
	print(start);
	
	printf("\n enter position after which you want to add new eleement\n");
	scanf("%d",&pos);
	printf("enter  new element\n");
	scanf("%d",&nel);
	addafterpos(start,pos,nel);
	print(start);			
}
	
