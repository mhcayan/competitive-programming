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
#define mod 100000007
const int inf=2000000000;
char str[1005];
long dp[1003][1003];
inline long min(long a,long b)
{
     return a<b?a:b;
}
long find(long i,long j)
{
     if(i>=j)
         return 0;
     if(dp[i][j]>-1)
         return dp[i][j];
     if(str[i]==str[j])
         return dp[i][j]=find(i+1,j-1);
     return dp[i][j]=1+min(find(i,j-1),find(i+1,j));
}
int main()
{
    long tc,l;
    scanf("%ld",&tc);
    getchar();
    while(tc--)
    {
        SET(dp);
        gets(str);
        l=strlen(str);
        printf("%ld\n",l-find(0,l-1));
    }
    return 0;
}
