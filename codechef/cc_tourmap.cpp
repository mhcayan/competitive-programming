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
    int cas,n,i,total,j,cst,start,no,deg[5005];
    string ct1,ct2,s,name[5005];
    char mo[55];
    vector<int>edge[5005];
    vector<int>cost[5005];
    map<string,int>mp;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            edge[i].clear();
            deg[i]=0;
            cost[i].clear();
        }
        mp.clear();
        no=0;
        total=0;
        i=n-1;
        while(i--)
        {
            cin>>ct1>>ct2>>s;
            for(j=0;s[j]!='$';j++)
                mo[j]=s[j];
            mo[j]='\0';
            cst=atoi(mo);
            total+=cst;
            if(mp.find(ct1)==mp.end())
            {
                mp[ct1]=++no;
                name[no]=ct1;
            }
            if(mp.find(ct2)==mp.end())
            {
                mp[ct2]=++no;
                name[no]=ct2;
            }
            edge[mp[ct1]].pb(mp[ct2]);
            cost[mp[ct1]].pb(cst);
            deg[mp[ct2]]++;
        }
        for(i=1;i<=no;i++)
            if(deg[i]==0)
            {
                start=i;
                break;
            }
                
        while(edge[start].size())
        {
            cout<<name[start]<<' '<<name[edge[start][0]]<<' '<<cost[start][0]<<'$'<<endl;
            start=edge[start][0];
        }
        printf("%d$\n",total);
            
    }
    return 0;
}
