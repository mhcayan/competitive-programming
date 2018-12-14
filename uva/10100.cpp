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
char a[1005],b[1005],s1[505][1005],s2[505][1005];
long dp[505][505];
inline long max(long x,long y)
{
     return x>y?x:y;
}
long lcs(long i,long j)
{
     if(i<0 || j<0)
         return 0;
     if(dp[i][j]>-1)
         return dp[i][j];
     if(strcmp(s1[i],s2[j])==0)
         return dp[i][j]=1+lcs(i-1,j-1);
     else
         return dp[i][j]=max(lcs(i-1,j),lcs(i,j-1));
}
int main()
{
    long i,j,k,l1,l2,tc=1;
    while(gets(a))
    {
        gets(b);
        l1=strlen(a);
        l2=strlen(b);
        if(l1==0 || l2==0)
            printf("%2ld. Blank!\n",tc++);
        else
        {
            SET(dp);
            j=0,k=0;
            for(i=0;i<=l1;i++)
            {
                if((a[i]>='a' && a[i]<='z')||(a[i]>='A' && a[i]<='Z')||(a[i]>='0' && a[i]<='9'))
                {
                    s1[j][k++]=a[i];
                }
                else
                {
                    if(k)
                    {
                        s1[j][k]='\0';
                        j++;
                        k=0;
                    }
                }
            }
            l1=j-1;
            s1[j][0]='\0';
            j=0,k=0;
            for(i=0;i<=l2;i++)
            {
                if((b[i]>='a' && b[i]<='z')||(b[i]>='A' && b[i]<='Z')||(b[i]>='0' && b[i]<='9'))
                {
                    s2[j][k++]=b[i];
                }
                else
                {
                    if(k)
                    {
                        s2[j][k]='\0';
                        j++;
                        k=0;
                    }
                }
            }
            s2[j][0]='\0';
            l2=j-1;
            printf("%2ld. Length of longest match: %ld\n",tc++,lcs(l1,l2));
        }  
            
    }
    return 0;
}
