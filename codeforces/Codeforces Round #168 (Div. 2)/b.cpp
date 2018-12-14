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
    int r,c,r1,r2,c1,c2,mx,mn,i,j,flag,k;
    char a[60][60];
    vector<pii>v;
    while(scanf("%d %d",&r,&c)==2)
    {
        v.clear();
        flag=0;
        for(i=0;i<r;i++)
        {
        scanf("%s",&a[i]);
            for(j=0;j<c;j++)
               if(a[i][j]=='B')
               v.pb(pii(i,j));
        }
        for(i=0;i<v.size();i++)
        {
            r1=v[i].ff;
            c1=v[i].ss;
            for(j=i+1;j<v.size();j++)
            {
                r2=v[j].ff;
                c2=v[j].ss;
                if(r1==r2)
                {
                    mx=max(c1,c2);
                    mn=min(c1,c2);
                                        for(k=mn;k<=mx;k++)
                    {
                        if(a[r1][k]=='W')
                            break;
                    }
                    if(k<=mx)
                    {
                        flag=1;
                        break;
                    }
                }
                else if(c1==c2)
                {
                    mx=max(r1,r2);
                    mn=min(r1,r2);
                    for(k=mn;k<=mx;k++)
                    {
                        if(a[k][c1]=='W')
                            break;
                    }
                    if(k<=mx)
                    {
                        flag=1;
                        break;
                    }
                }
                else
                {
                    mx=max(c1,c2);
                    mn=min(c1,c2);
                    for(k=mn;k<=mx;k++)
                    {
                        if(a[r1][k]=='W')
                            break;
                    }
                    if(k>mx)
                    {
                        mx=max(r1,r2);
                        mn=min(r1,r2);
                        for(k=mn;k<=mx;k++)
                        {
                            if(a[k][c2]=='W')
                                break;
                        }
                        if(k>mx)
                            continue;
                    }
                    mx=max(c1,c2);
                    mn=min(c1,c2);
                    for(k=mn;k<=mx;k++)
                    {
                        if(a[r2][k]=='W')
                            break;
                    }
                    if(k>mx)
                    {
                        mx=max(r1,r2);
                        mn=min(r1,r2);
                        for(k=mn;k<=mx;k++)
                        {
                            if(a[k][c1]=='W')
                                break;
                        }
                        if(k<=mx)
                        {
                            flag=1;
                            break;
                        }
                    }
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                }
                    
                       
            }
            if(flag)
            printf("NO\n");
            else
            printf("YES\n");
            
        
        
    }
    return 0;
}
