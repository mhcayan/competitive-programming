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
int dp[102][102];
char a[102];
inline int min(int x,int y)
{
	return x<y?x:y;
}

int find(int i,int j)
{
	if(i>=j)
		return 0;
	if(dp[i][j]>-1)
		return dp[i][j];
	if(a[i]==a[j])
		dp[i][j]=find(i+1,j-1);
	else
		dp[i][j]=1+min(find(i,j-1),find(i+1,j));
	return dp[i][j];
}
int main()
{
	int cas,t,l;
	scanf("%d\n",&cas);
	for(t=1;t<=cas;t++)
    {
		gets(a);
		l=strlen(a);
		SET(dp);
		printf("Case %d: %d\n",t,find(0,l-1));
    }
    return 0;
}
