#include<stdio.h>
#include<string.h>
#define CLR(a) memset(a,0,sizeof(a))
int main()
{
	int cas,tc,n,i,j,coin[200],way[10000],c,total;
	printf("Enter no of test cases:\n");
	scanf("%d",&cas);
	while(cas--)
	{
		printf("No of coins:\n");
		scanf("%d",&n);
		printf("Value of each coin:\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&coin[i]);
		}
		printf("no of amount to be checked:\n");
		scanf("%d",&tc);
		while(tc--)
		{
			CLR(way);
			way[0]=1;
			printf("Total amount:\n");
			scanf("%d",&total);
			for(i=0;i<n;i++)
			{
				c=coin[i];
				for(j=c;j<=total;j++)
				{
					way[j]+=way[j-c];
				}
			}
			printf("no of way=%d\n",way[total]);
		}
	}
	return 0;
}
