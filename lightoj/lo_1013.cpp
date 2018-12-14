#include<cstdio>
//#include<cstdlib>
//#include<cmath>
#include<cstring>
//#include<cctype>
//#include<string>
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<algorithm>
#include<map>
//#include<iterator>
using namespace std;
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
//const int inf=2000000000;
int dp[31][31];
big memo[62][31][31];
char a[32],b[32];
int lcs(int i,int j)
{
	if(i<0 || j<0)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(a[i]==b[j])
		return dp[i][j]=1+lcs(i-1,j-1);
	return dp[i][j]=max(lcs(i-1,j),lcs(i,j-1));
}
big find(int l,int i,int j)
{
    if(l==0)
    {
        if(i<0 && j<0)
            return 1;
        return 0;
    }
    if(i<0)
    {
           if(j<l)
               return 1;
           return 0;
    }
    if(j<0)
    {
           if(i<l)
               return 1;
           return 0;
    }
        
    if(memo[l][i][j]>-1)
        return memo[l][i][j];
	if(a[i]==b[j])
		return memo[l][i][j]=find(l-1,i-1,j-1);
	return memo[l][i][j]=find(l-1,i,j-1)+find(l-1,i-1,j);
}	
int main()
{
	int cas,t,l1,l2,l;
	scanf("%d\n",&cas);
	for(t=1;t<=cas;t++)
    {
		SET(dp);
		SET(memo);
		scanf("%s",&a);
		scanf("%s",&b);
		l1=strlen(a);
		l2=strlen(b);
		l=l1+l2-lcs(l1-1,l2-1);
		printf("Case %d: %d %lld\n",t,l,find(l,l1-1,l2-1));
    }
    return 0;
}
