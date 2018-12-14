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
inline int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	int cas,t,i,j,m,n,a[205][105];
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		CLR(a);
		scanf("%d",&n);
		m=2*n-1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
			    scanf("%d",&a[i][j]);
				a[i][j]+=max(a[i-1][j-1],a[i-1][j]);
			}
		}
		for(;i<=m;i++)
		{
			for(j=1;j<=m+1-i;j++)
			{
				scanf("%d",&a[i][j]);
				a[i][j]+=max(a[i-1][j],a[i-1][j+1]);
			}
		}
		printf("Case %d: %d\n",t,a[i-1][j-1]);
    }
    return 0;
}
