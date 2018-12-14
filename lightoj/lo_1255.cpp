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
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
char a[1000005],b[1000005];
int F[1000005];
void build(int m)
{
    int i,j;
    F[0]=F[1]=0;
    for(i=2;i<=m;i++)
    {
        j=F[i-1];
        while(1)
        {
            if(b[j]==b[i-1])
            {
                F[i]=j+1;
                break;
            }
            if(j==0)
            {
                F[i]=0;
                break;
            }
            j=F[j];
        }
    }
}
int main()
{
    int cas,tc,i,j,ans,m,n;
    scanf("%d\n",&cas);
    for(tc=1;tc<=cas;tc++)
    {
        gets(a);
        gets(b);
        ans=0;
        n=strlen(a);
        m=strlen(b);
        if(n>=m)
        {
            build(m);
            i=j=0;
            while(j<n)
            {
                while(1)
                {
                    if(a[j]==b[i])
                    {
                        i++;
                        if(i==m)
                        {
                            i=F[i];
                            ans++;
                        }
                        break;
                    }
                    if(i==0)
                        break;
                    i=F[i];
                }
                j++;
            }
        }
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
