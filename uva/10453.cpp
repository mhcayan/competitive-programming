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
long dp[1005][1005],b,e;
char str[1005],a[2010],s[1005][1005];
long find(long i,long j)
{
     if(i>j)
         return 0;
     if(dp[i][j]>-1)
         return dp[i][j];
     if(str[i]==str[j])
     {
         s[i][j]='e';
         return dp[i][j]=find(i+1,j-1);
     }
     long x,y;
     x=find(i+1,j);
     y=find(i,j-1);
     if(x<=y)
         s[i][j]='r';
     else
     {
         s[i][j]='l';    
         x=y;
     }
     return dp[i][j]=1+x;
}
void cons(long i,long j)
{
     if(i>j)
         return;
     if(s[i][j]=='e')
     {
         a[b++]=str[i],a[e--]=str[i];
         cons(i+1,j-1);
     }
     else if(s[i][j]=='l')
     {
          a[b++]=str[j],a[e--]=str[j];
          cons(i,j-1);
     }
     else
     {
         a[b++]=str[i],a[e--]=str[i];
         cons(i+1,j);
     }
     return;
}         
int main()
{
    long l,ans;
    while(gets(str))
    {
        SET(dp);
        l=strlen(str);
        ans=find(0,l-1);
        b=0;e=l+ans-1;
        a[e+1]='\0';
        cons(0,l-1);
        printf("%ld %s\n",ans,a);
        
    }
    return 0;
}

