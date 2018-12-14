#include<stdio.h>
#include<string.h>
long a[200000],status[200000];
int main()
{
	long t,c,i,n;
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%ld",&n);
		memset(status,0,sizeof(status));
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a[i]);
			status[a[i]]++;
		}
		for(i=n;i>0;i--)
		{
			if(status[a[i]]==1)
			{
				printf("case#%ld:%ld\n",t,a[i]);
				break;
			}
		}
		if(i==0)
			printf("case#%ld:-1\n",t);
	}
	return 0;
}