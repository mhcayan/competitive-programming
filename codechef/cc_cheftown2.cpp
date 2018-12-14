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
    deque<int>qmx,qmn;
    int n,w,i,a[400009],ans;
    scanf("%d %d",&n,&w);
    for(i=0;i<w;i++)
    {
        scanf("%d",&a[i]);
        while(!qmx.empty() && a[i]>qmx.back())
             qmx.pop_back();
        qmx.pb(a[i]);
        while(!qmn.empty() && a[i]<qmn.back())
             qmn.pop_back();
        qmn.pb(a[i]);
    }
    if(qmx.front()-qmn.front()==w-1)
        ans=1;
    else
        ans=0;
    for(;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(!qmx.empty() && qmx.front()==a[i-w])
            qmx.pop_front();
        if(!qmn.empty() && qmn.front()==a[i-w])
            qmn.pop_front();
        while(!qmx.empty() && a[i]>qmx.back())
             qmx.pop_back();
        qmx.pb(a[i]);
        while(!qmn.empty() && a[i]<qmn.back())
             qmn.pop_back();
        qmn.pb(a[i]);
        if(qmx.front()-qmn.front()==w-1)
            ans++;
    }     
    printf("%d\n",ans);
    getchar();
    return 0;
}
