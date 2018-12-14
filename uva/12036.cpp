#include<stdio.h>
int main()
{

	long c,t,count[1000],n,i,j,p,flag;
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%ld",&n);
		flag=1;
		for(i=0;i<101;i++)
			count[i]=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%ld",&p);
				count[p]++;
				if(count[p]>n)
					flag=0;
			}
		}
		if(flag)
			printf("Case %ld: yes\n",t);
		else
			printf("Case %ld: no\n",t);
	}
	return 0;
}
