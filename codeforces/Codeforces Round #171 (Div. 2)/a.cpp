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
    big total;
    int n,t,a[100009],mx,i;
    deque<int>q;
    while(scanf("%d %d",&n,&t)==2)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        while(!q.empty())
        q.pop_front();
        mx=0;
        total=0;
        for(i=0;i<n;i++)
        {
            if(total+a[i]>t)
            {
              if(q.size())
              {
                total-=q.front();
                q.pop_front();
                i--;
              }
            }
            else
            {
                total+=a[i];
                q.push_back(a[i]);
                if(q.size()>mx)
                    mx=q.size();
            }
           // printf("%d %d\n",q.size(),q.front());
        }
        printf("%d\n",mx);
                
    }
    return 0;
}
