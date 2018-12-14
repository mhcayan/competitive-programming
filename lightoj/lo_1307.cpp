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
#define ff first
#define ss second
#define pii pair<int,int>
#define psi pair<string,int>
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int cas,tc=1,n,a[2005],b,e,m,v,sum,i,j;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        sum=0;
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                v=a[i]+a[j];
                b=j+1;
                e=n;
                while(b<=e)
                {
                    m=(b+e)/2;
                    if(a[m]<v)
                        b=m+1;
                    else
                        e=m-1;
                }
                sum+=b-j-1;
            }
        }
        printf("Case %d: %d\n",tc++,sum);
    }
    return 0;
}
