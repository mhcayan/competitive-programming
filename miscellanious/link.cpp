#include<stdio.h>
#include<stdlib.h>
struct link{
	int num;
	struct link *next;
};

typedef struct link node;
void create(node *list);
int print_count(node *list);
/*node *insert(node *head);*/
node delete(node *);

int main()
{
	
	int count,ch;
	node *head;
	head=(node *)malloc(sizeof(node));
	create(head);
	printf("ENTER YOUR CHOICE\n1.PRINT LINKED LIST\n2.DELETE NODE\n3.INSERT NODE\n");
	printf("\n");
	while(scanf("%d",&ch)==1)
	{
		if(ch==1)
		{
			count=print_count(head);
	        printf("no. of elements=%d",count);
		}
		else if(ch==2)
		{
			delete(head);
		}
		else if(ch==3)
		{
			//insert(head);
		}
	}
	return 0;
}

void create(node *list)
{
	printf("\nENTER A NUMBER(enter -999 at last)\n");
	scanf("%d",&list->num);
	if(list->num==-999)
		list->next=NULL;
	else
	{
		list->next=(node *)malloc(sizeof(node));
		create(list->next);
	}
}

int print_count(node *list)
{
	if(list->next!=NULL)
	{
		printf("%d-->",list->num);
		return 1+print_count(list->next);
	}
	else{
		printf("%d",list->num);
		return 1;
	}
}

/*node *insert(node *head)
{
	int x,key;
	node *loc;
	node *new;
	node *find(node *list,int k);
	printf("Enter a number to insert\n");
	scanf("%d",&x);
	printf("Enter the key number (Enter -999 if last number)\n");
	scanf("%d",&key);
	if(key==head->num)
	{
		new=(node *)malloc(sizeof(node));
		new->num=x;
		new->next=head;
		head=new;
	}
	else
	{
		loc=find(head,key);
		if(loc==NULL)
			printf("key item is not found\n");
		else
		{
			new=(node *)malloc(sizeof(node));
	    	new->num=x;
		    new->next=loc->next;
		    loc->next=new;
		}
	}
	return head;
}*/

node delete(node *head)
{
	node *find(node *head);
	int x;
	node *p;
	printf("\nEnter the value to be deleted\n");
	scanf("%d",&x);
	if(x==head->number)
	{
		p=head->next;
		free(head);
		head=p;
	}
	else
	{
		loc=find(head,x);
		if("loc==NULL")
			printf("Number not found\n");
		else
		{
			p=loc-next->next;
			free(loc-next);
			loc->next=p;
		}
	}
	return head;
}

node *find(node *list,int k)
{
	if(list->next->num==k)
		return list;
	else if(list->next->next==NULL)
		return NULL;
	else
		find(list->next,k);
}