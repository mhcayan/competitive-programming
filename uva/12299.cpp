#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
long a[200000],m[999999];
int init(long node,long b,long e)
{
	if(b==e)
	{
		m[node]=a[b];
	}
	else
	{
	    init(node*2,b,(b+e)/2);
	    init(node*2+1,(b+e)/2+1,e);
	    if(m[node*2]<m[node*2+1])
		    m[node]=m[node*2];
	    else
		    m[node]=m[node*2+1];
	}
	return 0;
}
long query(long node,long b,long e,long i,long j)
{
	if(i<=b && e<=j)
		return m[node];
	if(i>e ||j<b)
		return -1;
	long p=query(node*2,b,(b+e)/2,i,j);
	long q=query(node*2+1,(b+e)/2+1,e,i,j);
	if(p==-1)
		return q;
	if(q==-1)
		return p;
	return p<q?p:q;
}
int update(long node,long b,long e,long i,long j)
{
	if(b==e)
	{
		m[node]=a[b];
		return 0;
	}
	if(i>e || j<b)
	{
		return 0;
	}
	else
	{
	    update(node*2,b,(b+e)/2,i,j);
	    update(node*2+1,(b+e)/2+1,e,i,j);
	    if(m[node*2]<m[node*2+1])
		    m[node]=m[node*2];
	    else
		    m[node]=m[node*2+1];
		return 0;
	}
}
int main()
{
	long n,q,i,k,x,y,j,b[100],t;
	char s[100],r[100];
	while(scanf("%ld %ld",&n,&q)==2)
	{
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		getchar();
		init(1,1,n);
		while(q--)
		{
			gets(s);
			if(s[0]=='q')
			{
				i=6;
				k=0;
				while(s[i]!=',')
				{
					r[k++]=s[i];
					i++;
				}
				r[k]='\0';
				x=atol(r);
				i++;
				k=0;
				while(s[i]!=')')
				{
					r[k++]=s[i];
					i++;
				}
				r[k]='\0';
				y=atol(r);
				printf("%ld\n",query(1,1,n,x,y));
			}
			else
			{
				i=6;
				j=0;
			    while(s[i])
				{
				    if(s[i]>='0' && s[i]<='9')
					{
						k=0;
					    while(s[i]>='0' && s[i]<='9')
						{
							r[k++]=s[i];
							i++;
						}
						//i--;
						r[k]='\0';
						b[j++]=atol(r);
					}
					i++;
				}
				t=a[b[0]];
				for(i=1;i<j;i++)
					a[b[i-1]]=a[b[i]];
				a[b[i-1]]=t;
/*				for(i=1;i<=n;i++)
				    printf("%ld ",a[i]);
				for(i=0;i<j;i++)
				{
					m[loc[b[i]]]=a[b[i]];
					update(loc[b[i]]);
				}
				printf("\n");*/
				update(1,1,n,b[0],b[j-1]);
			}
		}
	}
	return 0;
}
