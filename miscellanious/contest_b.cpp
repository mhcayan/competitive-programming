#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char str[1000];
	int t,a[1000],n,i,j,sum,c;
	scanf("%d",&c);
	for(t=1;t<=c;t++)
	{
		i=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",str);
			if(strcmp(str,"?"))
			{
				a[i++]=atoi(str);
			}
		}
		sum=0;
		for(j=1;j<i;j++)
		{
			sum+=abs(a[j]-a[j-1]);
		}
		printf("Case %d: %d\n",t,sum);
	}
	return 0;
}

