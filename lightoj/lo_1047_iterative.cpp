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
inline int min(int x,int y)
{
	return x<y?x:y;
}
int main()
{
	int cas,t,i,j,ans,n,a[22][4];
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<3;j++)
				scanf("%d",&a[i][j]);
		for(i=1;i<n;i++)
			for(j=0;j<3;j++)
				a[i][j]+=min(a[i-1][(j+1)%3],a[i-1][(j+2)%3]);
		ans=inf;
		for(i=0;i<3;i++)
			if(a[n-1][i]<ans)
				ans=a[n-1][i];
		printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
