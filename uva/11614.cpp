#include<stdio.h>
int main()
{
	int n,i,t,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		i=0;
		sum=0;
		while(sum<=n)
		{
			i++;
			sum+=i;
		}
		if(n==sum)
			printf("%d\n",i);
		else
			printf("%d\n",i-1);
	}
	return 0;
}