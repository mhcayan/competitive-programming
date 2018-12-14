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
#define pss pair<string,string>
const int inf=2000000000;
int main()
{
    int cas,n,i,total,j,cst,start,no,deg[5005];
    string ct1,ct2,s,name[5005];
    char mo[55];
    map<string,pss>mp;
    map<string,bool>vis
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        mp.clear();
        total=0;
        i=n-1;
        while(i--)
        {
            cin>>ct1>>ct2>>cst;
            mp[ct1]=pss(ct2,cst);
            if(deg.find(ct1)==deg.end())
            {
                v.pb(ct1);
                deg[ct1]=0;
            }
            else
                deg[ct1]++;
            if(deg.find(ct2)==deg.end())
            {
                v.pb(ct2);
                deg[ct2]=0;
            }
            else
                deg[ct2]+=2;
        }
        for(it=v.begin();it!=v.end();it++)
            if(deg[*it]==1)
            {
               ct1=*it;
               break;
            }
        while(mp.find(ct1))
        {
            cout<<ct1<<' '<<mp[ct1].ff<<' '<<mp[ct1].ss<<endl;
            sscanf(mp[ct1].ss.c_str(),"%d$",&value);
            total+=value;
        
            
   
            
    }
    return 0;
}
