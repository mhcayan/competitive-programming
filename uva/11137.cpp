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
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
long a[24];
big dp[23][10002];
big find(long i,long t)
{
	if(i==0)
	{
		if(!t)
			return 1;
		else
			return 0;
	}
	if(t==0)
		return 1;
	if(t<0)
		return 0;
	if(dp[i][t]>-1)
		return dp[i][t];
	return dp[i][t]=find(i-1,t)+find(i,t-a[i]);
}
int main()
{
	long i,t;
	for(i=1;i<=21;i++)
		a[i]=i*i*i;
	SET(dp);
	while(scanf("%ld",&t)==1)
    {
		printf("%lld\n",find(21,t));
    }
    return 0;
}
