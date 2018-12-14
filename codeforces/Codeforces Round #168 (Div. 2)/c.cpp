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
#include<sstream>
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
    big n,k,i,b,e,m,ans,v,a[100009],s;
    bool flag[100009];
    while(scanf("%I64d %I64d",&n,&k)==2)
    {
        for(i=0;i<n;i++)
            scanf("%I64d",&a[i]);
        sort(a,a+n);
        if(k==1)
        printf("%I64d\n",n);
        else
        {
        ans=n;
        CLR(flag);
        for(i=0;i<n;i++)
        {
            if(flag[i])
                continue;
            v=a[i]*k;
            flag[i]=1;
            s=1;
            b=i+1;
            e=n-1;
            while(b<=e)
            {
                m=(b+e)/2;
                if(v==a[m])
                {
                    //printf("%d\n",m);
                    flag[m]=1;
                    v=v*k;
                    b=m+1;
                    e=n-1;
                    s++;
                }
                else if(v>a[m])
                    b=m+1;
                else
                   e=m-1;
            }
            ans-=s/2;
        }
        printf("%I64d\n",ans);
        }
    }
    return 0;
}
