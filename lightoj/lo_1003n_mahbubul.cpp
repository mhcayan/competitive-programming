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
#define ff first
#define ss second
typedef pair<int,big>pib;
//const int inf=2000000000;
bool vis[32][32];
pib dp[32][32];
big find(int i,int j)
{
    if(a[i]==a[j])
        x=find(i+1,j+1);
    
}	
int main()
{
	int cas,t;
	scanf("%d\n",&cas);
	for(t=1;t<=cas;t++)
    {
		SET(dp);
		SET(memo);
		scanf("%s",&a);
		scanf("%s",&b);
		l1=strlen(a);
		l2=strlen(b);
		x=find(0,0);
		printf("Case %d: %d %lld\n",t,l,x.ff);
    }
    return 0;
}
