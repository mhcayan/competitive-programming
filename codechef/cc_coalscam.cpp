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
int par[5005];
struct data{
       int u,v,c;
};
vector<data>chef;
vector<data>other;
data ed;
bool cmp1(data a,data b)
{
     return a.c>b.c;
}
bool cmp2(data a,data b)
{
     return a.c<b.c;
}
int find(int u)
{
    if(u==par[u])
        return u;
    return par[u]=find(par[u]);
}
int main()
{
    int cas,n,m1,m2,i,u,v,count,tc=1;
    big cost,profit;
    scanf("%d",&cas);
    while(cas--)
    {
        chef.clear();
        other.clear();
        scanf("%d %d %d",&n,&m1,&m2);
        while(m1--)
        {
            scanf("%d %d %d",&ed.u,&ed.v,&ed.c);
            other.pb(ed);
        }
        while(m2--)
        {
            scanf("%d %d %d",&ed.u,&ed.v,&ed.c);
            chef.pb(ed);
        }
        sort(chef.begin(),chef.end(),cmp1);
        sort(other.begin(),other.end(),cmp2);
        count=n-1;
        for(i=0;i<=n;i++)
            par[i]=i;
        profit=0;
        for(i=0;i<chef.size();i++)
        {
            u=find(chef[i].u);
            v=find(chef[i].v);
            if(u!=v)
            {
                par[u]=v;
                profit+=chef[i].c;
                count--;
                if(!count)
                    break;
            }
        }
        cost=0;
        if(count)
        {
            for(i=0;i<other.size();i++)
            {
                u=find(other[i].u);
                v=find(other[i].v);
                if(u!=v)
                {
                    par[u]=v;
                    cost+=other[i].c;
                    count--;
                    if(!count)
                        break;
                }
            }
        }
        if(count==0)
            printf("%lld %lld\n",profit,profit+cost);
        else
            printf("Impossible\n");
               
    }
    return 0;
}
