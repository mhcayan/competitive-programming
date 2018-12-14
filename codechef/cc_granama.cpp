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
    int cas,i,chef,actual,F[150],S[150];
    char s1[2000],s2[2000];
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%s %s",s1,s2);
        CLR(F);
        CLR(S);
        for(i=0;s1[i];i++)
            F[s1[i]]++;
        for(i=0;s2[i];i++)
            S[s2[i]]++;
        chef=1;
        actual=1;
        for(i='a';i<='z';i++)
        {
            if(F[i])
            {
                if(S[i]==0)
                {
                    chef=0;
                    actual=0;
                    break;
                }
                else if(S[i]!=F[i])
                    actual=0;
            }
            else if(S[i])
            {
                 chef=0;
                 actual=0;
                 break;
            }
        }
        if(chef==actual)
            printf("YES\n");
        else
            printf("NO\n");
                    
    }
    return 0;
}
