#include<stdio.h>
long a[100010],m[300000];
void init(long node,long b,long e)
{
	if(b==e)
	{
		m[node]=a[b];
		return;
	}
	long mid=(b+e)/2;
	long c=node*2;
	init(c,b,mid);
	init(c+1,mid+1,e);
	m[node]=m[c]<m[c+1]?m[c]:m[c+1];
	return;
}
long query(long node,long b,long e,long i,long j)
{
	if(i>e || j<b)
		return -1;
	if(i<=b && e<=j)
		return m[node];
	long mid=(b+e)/2;
	long p=query(node*2,b,mid,i,j);
	long q=query(node*2+1,mid+1,e,i,j);
	if(p==-1)
		return q;
	if(q==-1)
		return p;
	return (p<q)?p:q;
}
int main()
{
	long n,cas,t,q,i,j;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld %ld",&n,&q);
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		init(1,1,n);
		printf("Case %ld:\n",t);
		while(q--)
		{
			scanf("%ld %ld",&i,&j);
			printf("%ld\n",query(1,1,n,i,j));
		}
	}
	return 0;
}

