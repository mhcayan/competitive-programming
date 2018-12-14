#include<stdio.h>
int main()
{
	int c,t,n,p,q,min,w[50],i,e,tw;
	scanf("%d",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%d %d %d",&n,&p,&q);
		min=n>p?p:n;
		for(i=0;i<n;i++)
			scanf("%d",&w[i]);
		e=0;
		tw=0;
		for(i=0;i<min;i++)
		{
			if(tw+w[i]<=q)
			{
				e++;
				tw+=w[i];
			}
			else
				break;
		}
		printf("Case %d: %d\n",t,e);
	}
	return 0;
}
