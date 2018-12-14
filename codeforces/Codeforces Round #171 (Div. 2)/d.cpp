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
    int x,y,total;
    while(scanf("%d %d",&x,&y)==2)
    {
                if(x>0 && x==y)
            total=1+(x-1)*4;
        else if(x<0 && x==y)
            total=4*(-x)-1;
        else if(x<0 && x==-y)
            total=4*y-2;
        else if(x>0 && x+y==1)
            total=4*x-4;
        else
        {
        if(y>0 && abs(x)<y)
            x=-y;
        else if(x>0 && y>-(x-1)&& y<x) 
            y=x;
        else if(x<0 && abs(x)>abs(y))
            y=x;
        else
            x=abs(y)+1;
        if(x>0 && x==y)
            total=1+(x-1)*4;
        else if(x<0 && x==y)
            total=4*(-x)-1;
        else if(x<0 && x==-y)
            total=4*y-2;
        else if(x>0 && x+y==1)
            total=4*x-4;
        }
        printf("%d\n",total);
        
        
    }
    return 0;
}
