#include<stdio.h>
long m[300000],a[300000];
void init(long node,long b,long e)
{
	if(b==e)
	{
		if(m[node])
		{
			a[node]=0;
			m[node]=0;
		}
		return;
	}
	if(m[node]==0)
		return;
	m[node]=0;
	a[node]=0;
	long c,mid;
	c=node*2;
	mid=(b+e)/2;
	init(c,b,mid);
	init(c+1,mid+1,e);
}
void update(long node,long b,long e,long i,long j,long v)
{
	if(j<b || i>e)
		return;
	if(i<=b && e<=j)
	{
		m[node]+=(e-b+1)*v;
		a[node]+=v;
		return;
	}
	long mid,c;
	mid=(b+e)/2;
	c=2*node;
	if(b<=i && j<=e)
	{
		m[node]+=v*(j-i+1);
		update(c,b,mid,i,j,v);
		update(c+1,mid+1,e,i,j,v);
		return;
	}
	if(i<=b)
	{
		m[node]+=(j-b+1)*v;
		update(c,b,mid,i,j,v);
		update(c+1,mid+1,e,i,j,v);
		return;
	}
	m[node]+=(e-i+1)*v;
	update(c,b,mid,i,j,v);
	update(c+1,mid+1,e,i,j,v);
	return;
}

long query(long node,long b,long e,long i,long j)
{
	if(j<b || i>e)
		return 0;
	if((i<=b && e<=j) || m[node]==0)
		return m[node];
	long mid,c;
	mid=(b+e)/2;
	c=2*node;
	if(b<=i && j<=e)
		return (j-i+1)*a[node]+query(c,b,mid,i,j)+query(c+1,mid+1,e,i,j);
	if(i<=b)
		return (j-b+1)*a[node]+query(c,b,mid,i,j)+query(c+1,mid+1,e,i,j);
	return (e-i+1)*a[node]+query(c,b,mid,i,j)+query(c+1,mid+1,e,i,j);
}
int main()
{
	long cas,t,n,q,qt,i,j,v;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld %ld",&n,&q);
		printf("Case %ld:\n",t);
		while(q--)
		{
			scanf("%ld %ld %ld",&qt,&i,&j);
			if(qt)
				printf("%ld\n",query(1,0,n-1,i,j));
			else
			{
				scanf("%ld",&v);
				update(1,0,n-1,i,j,v);
			}
		}
		if(t<=cas)
			init(1,0,n-1);
	}
	return 0;
}
