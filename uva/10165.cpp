#include<stdio.h>
int main()
{
	long n,p,flag;
	while(scanf("%ld",&n) && n!=0)
	{
		if(n%2==0)
			flag=0;
		else
			flag=1;
		while(n--)
			scanf("%ld",&p);
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
		