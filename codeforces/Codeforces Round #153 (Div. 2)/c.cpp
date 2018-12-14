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
    int n,d,i,beg,end,a[100005],mid;
    big ans;
    while(scanf("%d %d",&n,&d)==2)
    {
        for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
        ans=0;
        for(i=1;i<=n-2;i++)
        {
            beg=i+1;
            end=n-1;
            while(beg<=end)
            {
                mid=(end+beg)/2;
                if(a[mid]-a[i]<=d)
                    beg=mid+1;
                else
                    end=mid-1;
            }
            cout<<end<<endl;
            if(end>i)
            {
                ans+=((end-i-1+n-i+1)*(n-end+1))/2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
