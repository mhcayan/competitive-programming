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
char a[32],b[32];
bool vis[32][32];
pib dp[32][32];
int l1,l2;
pib find(int i,int j)
{
    if(i==l1)
    {
        if(j==l2)
            return pib(0,1);
        return pib(l2-j,1);
    }
    if(j==l2)
        return pib(l1-i,1);
    if(vis[i][j])
        return dp[i][j];
    vis[i][j]=1;
    pib x,y;
    if(a[i]==b[j])
    {
        x=find(i+1,j+1);
        x.ff++;
        return dp[i][j]=x;
    }
    x=find(i,j+1);
    y=find(i+1,j);
    x.ff++,y.ff++;
    if(x.ff==y.ff)
    {
        return dp[i][j]=pib(x.ff,x.ss+y.ss);
    }
    if(x.ff<y.ff)
        return dp[i][j]=x;
    return dp[i][j]=y;
}	
int main()
{
	int cas,t;
	pib x;
	scanf("%d\n",&cas);
	for(t=1;t<=cas;t++)
    {
        CLR(vis);
		scanf("%s",&a);
		scanf("%s",&b);
		l1=strlen(a);
		l2=strlen(b);
		x=find(0,0);
		printf("Case %d: %d %lld\n",t,x.ff,x.ss);
    }
    return 0;
}
