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
int main()
{
	int cas,tc,i,n,cnt,s,b,a[50002];
	scanf("%d",&cas);
	for(tc=1;tc<=cas;tc++)
    {
		scanf("%d%d",&n,&s);
		for(i=0;i<n;i++)
			scanf("%d %d",&cnt,&a[i]);
		sort(a,a+n);
		cnt=0;
		b=-inf;
		for(i=0;i<n;i++)
		{
			if(a[i]>b)
			{
				b=a[i]+s;
				cnt++;
			}
		}
		printf("Case %d: %d\n",tc,cnt);
    }
    return 0;
}
