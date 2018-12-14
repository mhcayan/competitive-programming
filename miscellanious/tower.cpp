#include<stdio.h>
//void tower(long,char,char,char);
int main()
{
	long n;
	scanf("%ld",&n);
void tower(long n,char a,char b,char c)
{
	if(n==1)
	{
		printf("%c>%c\n",a,c);
		return;
	}
	else
	{
	   tower(n-1,'a','c','b');
	   printf("%c>%c\n",a,c);
	   tower(n-1,'b','a','c');
	}
}
	
	return 0;
}
