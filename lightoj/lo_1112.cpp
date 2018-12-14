#include<stdio.h>
long a[100005],m[300000];
void init(long node,long b,long e)
{
	if(b==e)
	{
		m[node]=a[b];
		return;
	}
	long mid,c;
	mid=(b+e)/2;
	c=node*2;
	init(c,b,mid);
	init(c+1,mid+1,e);
	m[node]=m[c]+m[c+1];
}
long sum(long node,long b,long e,long i,long j)
{
	if(e<i || b>j)
		return -1;
	if(i<=b && e<=j)
		return m[node];
	long mid,p,q;
	mid=(b+e)/2;
	p=sum(node*2,b,mid,i,j);
	q=sum(node*2+1,mid+1,e,i,j);
	if(p==-1)
		return q;
	if(q==-1)
		return p;
	return p+q;
}
void give(long node,long b,long e,long i)
{
	if(i<b || i>e)
		return;
	if(b==e && i==b)
	{
		m[node]=0;
		return;
	}
	long mid,c;
	mid=(b+e)/2;
	c=node*2;
	give(c,b,mid,i);
	give(c+1,mid+1,e,i);
	m[node]=m[c]+m[c+1];
}
void add(long node,long b,long e,long i,long v)
{
	if(i<b || i>e)
		return;
	if(b==e && i==b)
	{
		m[node]+=v;
		return;
	}
	long mid,c;
	mid=(b+e)/2;
	c=node*2;
	add(c,b,mid,i,v);
	add(c+1,mid+1,e,i,v);
	m[node]=m[c]+m[c+1];
}
int main()
{
	long cas,t,n,q,i,j,v,tn;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld %ld",&n,&q);
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		init(1,0,n-1);
		printf("Case %ld:\n",t);
		while(q--)
		{
			scanf("%ld %ld",&tn,&i);
			if(tn==1)
			{
				printf("%ld\n",a[i]);
				a[i]=0;
				give(1,0,n-1,i);
			}
			else if(tn==2)
			{
				scanf("%ld",&v);
				a[i]+=v;
				add(1,0,n-1,i,v);
			}
			else
			{
				scanf("%ld",&j);
				printf("%ld\n",sum(1,0,n-1,i,j));
			}
		}
	}
	return 0;
}