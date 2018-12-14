#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iterator>
using namespace std;
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
const int inf=2000000000;
inline int max(int x,int y)
{
	return x>y?x:y;
}
inline int min(int x,int y)
{
	return x<y?x:y;
}
typedef struct{
	int mx,mn;
}value;
value m[450000],bas={-inf,inf};
int a[100005];
void init(int node,int b,int e)
{
	if(b==e)
	{
		m[node].mx=a[b];
		m[node].mn=a[b];
		return;
	}
	int mid=(b+e)/2;
	init(node*2,b,mid);
	init(node*2+1,mid+1,e);
	m[node].mx=max(m[node*2].mx,m[node*2+1].mx);
	m[node].mn=min(m[node*2].mn,m[node*2+1].mn);
}
value query(int node,int b,int e,int i,int j)
{
	if(i>e || j<b)
		return bas;
	if(i<=b && e<=j)
		return m[node];
	else
	{
		value p1,p2,v;
		int mid=(b+e)/2;
		p1=query(node*2,b,mid,i,j);
		p2=query(node*2+1,mid+1,e,i,j);
		if(p1.mx>p2.mx)
			v.mx=p1.mx;
		else
			v.mx=p2.mx;
		if(p1.mn>p2.mn)
			v.mn=p2.mn;
		else
			v.mn=p1.mn;
		return v;
	}
}
		
int main()
{
	int cas,t,n,d,i,j,diff;
	value v;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		scanf("%d %d",&n,&d);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		init(1,0,n-1);
		d--;
		i=0;
		j=i+d;
		diff=0;
		if(d)
		while(j<n)
		{
			v=query(1,0,n-1,i,j);
			//printf("%d %d\n",v.mx,v.mn);
			if(v.mx-v.mn>diff)
				diff=v.mx-v.mn;
			i++;
			j=i+d;

		}
		printf("Case %d: %d\n",t,diff);
		
    }
    return 0;
}
