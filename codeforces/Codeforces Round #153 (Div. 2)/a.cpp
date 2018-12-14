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
    int i,j,n,r,mx,a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
                    scanf("%d",&a[i]);
    }
    mx=-1;
    for(i=0;i<n;i++)
    {
        r=a[i];
        if(r>mx)
        mx=r;
        for(j=0;j<n;j++)
        {
           r=r^a[j];
           if(r>mx)
             mx=r;
        }
        }
        printf("%d\n",mx);
    return 0;
}
