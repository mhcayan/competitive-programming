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
    int res,i,c[200];
    char a[10000],ch;
    while(gets(a))
    {
       CLR(c);
        for(i=0;a[i];i++)
        {
            c[a[i]]++;
        }
         res=0;
         for(ch='a';ch<='z';ch++)
         {
         if(c[ch]%2==1)
         res++;
         }
        if(res%2 || res==0)
        printf("First\n");
        else
        printf("Second\n");
    }
    return 0;
}
