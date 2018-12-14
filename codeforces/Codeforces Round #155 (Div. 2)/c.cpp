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

#define sd(a) scanf("%d",&a)
#define sd2(a) scanf("%d %d",&a,&b)
#define slf(a) scanf("%lf",&a)
const int inf=2000000000;
int main()
{
//    freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    char s[100005],t[100005],ch;
    int i,ans,frs[300],frt[300],skip[300];
    while(scanf("%s %s",s,t)==2)
    {
        for(ch='A';ch<='Z';ch++)
        {
            frs[ch]=0;
            frt[ch]=0;
            skip[ch]=0;
        }
        for(i=0;s[i];i++)
        {
            frs[s[i]]++;
            frt[t[i]]++;
        }
        queue<char>q;
        for(ch='A';ch<='Z';ch++)
        {
            if(frs[ch]<frt[ch])
                q.push(ch);
        }
        ans=0;
        for(i=0;s[i];i++)
        {
            if(frs[s[i]]>frt[s[i]])
            {
                ch=q.front();
                if(ch>s[i] && skip[s[i]]<frt[s[i]])
                {
                    skip[s[i]]++;
                    continue;
                }
                ans++;
                frs[s[i]]--;
                frs[ch]++;
                s[i]=ch;
                if(frs[s[i]]==frt[s[i]])
                    q.pop();
            }
        }
        printf("%d\n%s\n",ans,s);
                
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
