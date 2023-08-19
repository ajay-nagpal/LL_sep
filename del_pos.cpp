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
struct node* del(struct node* start,int pos,int n)
{
	struct node *tmp=start;
	int posh=1;
	
	if(start->next==NULL&&pos==1)
	{
		free(start);
		start=NULL;
		return start;
	}
	else if(pos==1&&start->next!=NULL)
		{
		tmp=start;
		start=start->next;
		start->prev=NULL;
		free(tmp);
		tmp=NULL;
		return start ;			
		}
		
		else if(pos>1&&pos<n)
		{
			while(posh!=pos)
			{
				posh++;
				tmp=tmp->next;	
			}
			
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			free(tmp);
			tmp=NULL;
			return start;
	
		}

			
		else //if(pos==n)
		{
			
			while(posh!=pos)
			{
				tmp=tmp->next;
				posh++;
			}
			tmp->prev->next=NULL;
			free(tmp);
			tmp=NULL;
			return start;
			
		}
	
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
	
	printf("\n enter the pos where you want to delete element \n");
	scanf("%d",&pos);
	if(pos>n)
	{
		printf(" position does not exist in list so list remain same\n");
		return 0;
		
	}
	start=del(start,pos,n);
	
	printf("\n so the list is\n");
		print(start);

}

