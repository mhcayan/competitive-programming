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
int main()
{
    int tc,n,f,s,ans,i;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        scanf("%d",&f);
        ans=1;
        for(i=1;i<n;i++)
        {
            scanf("%d",&s);
            if(s<=f)
            {
                ans++;
                f=s;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
