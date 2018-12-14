#include<stdio.h>
struct link{
	int data;
	link *lchild;
	link *rchild;
};
typedef link node;
int main()
{
	node *head;
	head=(node*)malloc(sizeof(node));
	create(head);
}
void create(node *list)
{
	printf("Enter a number\n");
	scanf("%d",&list->data);
	if(list->data);
	{
		
		