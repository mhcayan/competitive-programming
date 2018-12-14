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
int rmq(int node,int b,int e)
{
	if(b==e)
	{
		m[node].mx=a[b];
		m[node].lmx=a[b];
		m[node].rmx=a[b]
		return m[node];
	}
	mid=(b+e)/2;
	int c=node*2;
	int u=rmq(c,b,mid);
	int v=rmq(c+1,mid+1,e);
	m[node].mx=max(m[c].mx,m[c+1].mx);
	value=m[c].rmx+m[c+1].lmx-max(a[mid],a[mid+1]);
	if(value>=m[node].mx)
	{
		m[node].mx=value;
		m[node].

int main()
{
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("Case %d: %d\n",t,rmq(1,0,n-1));
    }
    return 0;
}
