#include<stdio.h>
int main()
{
	int t,n,k,p,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d %d",&n,&k,&p);
		while(p)
		{
			k++;
			if(k>n)
				k=1;
			p--;
		}
		printf("Case %d: %d\n",i,k);
	}
	return 0;
}