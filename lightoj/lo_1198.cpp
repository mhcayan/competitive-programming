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
#include<set>
using namespace std;
#define ulong unsigned long
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
int dp[55][55],a[55],b[55];
inline int max(int x,int y)
{
	return x>y?x:y;
}
int find(int i,int j)
{
	if(i<0||j<0)
		return 0;
	if(dp[i][j]>-1)
		return dp[i][j];
	int k;
	int v=0;
	for(k=j;k>=0;k--)
	{
		if(b[k]==a[i])
		{
			v=max(v,1+find(i-1,k-1));
	//		if(k-1>=0)
	//			dp[i][j]=max(dp[i][j],2+find(i-1,k-2));
//			break;
	}
		else if(b[k]<a[i])
		{
			v=max(v,2+find(i-1,k-1));
			break;
		}
	}
	return dp[i][j]=v;
}
int main()
{
	int cas,tc,i,n;
	scanf("%d",&cas);
	for(tc=1;tc<=cas;tc++)
    {
		SET(dp);
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		printf("Case %d: %d\n",tc,find(n-1,n-1));
    }
    return 0;
}
