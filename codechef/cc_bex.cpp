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
struct{
       char name[20];
       int num,min;
}list[1000005];
int main()
{
    int n,v,i,loc;
    char s[20];
    scanf("%d\n",&n);
    i=0;
    while(n--)
    {
        scanf("%d",&v);
        if(v!=-1)
        {
            //sscanf(str,"%d %s",&v,s);
            scanf("%s",s);
            if(v==0)
                continue;
            i++;
            //printf("%s\n",s);
            strcpy(list[i].name,s);
            if(i==1)
            {
                list[i].num=v;
                list[i].min=i;
            }
            else
            {
                list[i].num=v;
                if(list[list[i-1].min].num<v)
                    list[i].min=list[i-1].min;
                else
                {
                    list[i].min=i;
                }
                    
            }
        }
        else
        {
            loc=list[i].min;
            printf("%d %s\n",i-loc,list[loc].name);
            i=loc-1;
        }
    }
    return 0;
}
