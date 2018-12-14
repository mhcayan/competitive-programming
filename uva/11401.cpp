#include<stdio.h>
int main()
{
	long m,n,p,i,j,k,count;
	while(scanf("%ld",&n) && n>2)
	{
		m=n-2;
		p=n-1;
		count=0;
		for(i=1;i<=m;i++)
		{
			for(j=i+1;j<=p;j++)
			{
				for(k=j+1;k<=n;k++)
				{
					if(i+j>k)
						count++;
					else
						break;
				}
			}
		}
		printf("%ld\n",count);
	}
	return 0;
}