
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
#define md 10000007
const int inf=2000000000;
int dp[10002][102],coin[102];
int find(int k,int n)
{
	if(k==0)
		return 1;
	if(k<0 || n<0)
		return 0;
	if(dp[k][n]>-1)
		return dp[k][n];
	return dp[k][n]=(find(k-coin[n],n)%md+find(k,n-1)%md)%md;
}
int main()
{
	int cas,t,n,k,i;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		SET(dp);
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&coin[i]);
		printf("Case %d: %d\n",t,find(k,n-1));
    }
    return 0;
}
