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
#define ulong unsigned long
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
int main()
{
    int cas,tc,n,loc[105],a[105],i,c,tmp;
    scanf("%d",&cas);
    for(tc=1;tc<=cas;tc++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            loc[a[i]]=i;
        }    
        c=0;
        for(i=1;i<=n;i++)
        {
			tmp=loc[i];
            if(tmp!=i)
            {
                swap(a[i],a[tmp]);
                loc[a[i]]=i;
                loc[a[tmp]]=tmp;
                c++;
            }
        }
        printf("Case %d: %d\n",tc,c);
    }
    return 0;
}
