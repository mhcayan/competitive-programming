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
int dp[25][4],a[25][4],n;
inline int min(int x,int y)
{
	return x<y?x:y;
}
int find(int i,int j)
{
	if(i==n)
		return 0;
    if(dp[i][j])
		return dp[i][j];
	return dp[i][j]=a[i][j]+min(find(i+1,(j+1)%3),find(i+1,(j+2)%3));
}
int main()
{
	int cas,t,i,j,ans,res;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<3;j++)
				scanf("%d",&a[i][j]);
		ans=inf;
		for(i=0;i<3;i++)
		{
			CLR(dp);
			res=find(0,i);
			if(res<ans)
				ans=res;
		}
		printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
