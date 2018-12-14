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
    int i,j,k,sum,m,n,a[5][5],b[5][5],xx[5]={0,-1,0,1},yy[5]={-1,0,1,0};
    for(i=1;i<=3;i++)
    for(j=1;j<=3;j++)
    scanf("%d",&a[i][j]);
    for(i=1;i<=3;i++)
    for(j=1;j<=3;j++)
    {
        sum=a[i][j];
        for(k=0;k<4;k++)
        {
          m=i+xx[k];
          n=j+yy[k];
          if(m>0 && m<=3 && n>0 && n<=3)
            sum+=a[m][n];
        }
        if(sum%2==0)
          b[i][j]=1;
        else
        b[i][j]=0;
    }
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        printf("%d",b[i][j]);
        printf("\n");
    }
    //getchar();
    //getchar();
    return 0;
}
