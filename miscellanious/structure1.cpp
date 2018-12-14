#include<stdio.h>
struct store{
	char name[100];
	int price;
	int quantity;
};
struct store increment(struct store item,int p,int q);
int main()
{
	int p_incr,q_incr ;
	struct store item={"aaa",60,1};
	printf("Enter price & quantity incremrnt .\n");
	scanf("%d %d",&p_incr,&q_incr);
	item=increment(item,p_incr,q_incr);
	printf("Updated values of item\n\n");
	printf("%s %ld %ld\n",item.name,item.price,item.quantity);
	return 0;
}
struct store increment(struct store item,int p,int q)
{
	item.price+=p;
	item.quantity=+q;
	return item;
}
	
