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
#define ff first
#define ss second
#define pii pair<int,int>
#define psi pair<string,int>
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
int tree[2250009][30];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j,k,l,ans,node,bad,total;
    char str[1510],s[30],ch;
    while(scanf("%s",str)==1)
    {
        scanf("%s",s);
        for(i=0;s[i];i++)
           s[i]-='0';
        scanf("%d",&k);
        total=0;
        ans=0;
        for(i=0;i<26;i++)
            tree[0][i]=-1;
        for(i=0;str[i];i++)
        {
            bad=0;
            node=0;
            for(j=i;str[j];j++)
            {
                ch=str[j]-'a';
                if(s[ch]==0)
                    bad++;
                if(bad>k)
                    break;
                if(tree[node][ch]==-1)
                {
                    ans++;
                    tree[node][ch]=++total;
                    for(l=0;l<26;l++)
                        tree[total][l]=-1;
                }
                node=tree[node][ch];
            }
        }
        printf("%d\n",ans);
                
                
    }
    return 0;
}
