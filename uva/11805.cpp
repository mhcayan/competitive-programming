#include<stdio.h>
int main()
{
	int t,n,k,p,b,i=1;
	scanf("%d",&t);
	while(i<=t)
	{
		scanf("%d %d %d",&n,&k,&p);
		b=k+p;
		if(b>n)
		{
			while(b>n)
				b-=n;
		}
		printf("Case %d: %d\n",i,b);
		i++;

	}
	return 0;
}
