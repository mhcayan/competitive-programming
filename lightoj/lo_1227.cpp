#include<stdio.h>
int main()
{
	int cas,t,n,p,q,w[50],i,tw;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%d %d %d",&n,&p,&q);
		for(i=0;i<n;i++)
			scanf("%d",&w[i]);
		tw=0;
		i=0;
		if(p>n)
			p=n;
		while(i<p)
		{
			tw+=w[i];
			if(tw>q)
				break;
			i++;
		}
		printf("Case %d: %d\n",t,i);
	}
	return 0;
}