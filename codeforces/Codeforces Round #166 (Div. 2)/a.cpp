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
int main()
{
    int m,n,i,j,a[6],f;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n)==1)
    {
    
        while(1)
        {
                n++;
            m=n;
            i=0;
            while(m)
            {
                a[i++]=m%10;
                m/=10;
            }
            f=0;
            for(i=0;i<4;i++)
            for(j=i+1;j<4;j++)
            if(a[i]==a[j])
            {
                f=1;
            }
            if(f==0)
            break;
        }
        printf("%d\n",n);
    }
    return 0;
}
