
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
#define md 100000007
//const int inf=2000000000;
int main()
{
	int cas,t,n,k,i,way[10005],coin[102],j,c;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		CLR(way);
		way[0]=1;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&coin[i]);
		for(i=0;i<n;i++)
		{
			c=coin[i];
			for(j=c;j<=k;j++)
			{
				way[j]+=way[j-c];
				if(way[j]>=md)
					way[j]%=md;
			}

		}
		printf("Case %d: %d\n",t,way[k]);
    }
    return 0;
}
