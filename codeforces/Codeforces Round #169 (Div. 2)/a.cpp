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
    int n,k,f,max,t,v;
    while(scanf("%d %d",&n,&k)==2)
    {
                    max=-inf;
                    while(n--)
                    {
                              scanf("%d %d",&f,&t);
                              if(t>k)
                              v=f-(t-k);
                              else
                              v=f;
                              if(v>max)
                              max=v;
                              }
                              printf("%d\n",max);
                              }
    
    return 0;
}
