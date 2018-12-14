#include<stdio.h>
int main()
{
	int t,n,s,max,i,j;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		max=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&s);
			if(s>max)
				max=s;
		}
		printf("Case %d: %d\n",i,max);
	}
	return 0;
}
