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
#define pii pair<big,big>
#define psi pair<string,big>
#define eps 1e-11
#define mod 100000007
const big inf=2000000000;
big F[700005],a[200005],q1[200005],q2[200005],v[200005];
void update(big node,big b,big e,big i,big j)
{
     if(i>e || j<b)
        return;
     if(i<=b && e<=j)
     {
        F[node]++;
        return;
     }
     big m=(b+e)/2;
     update(node*2,b,m,i,j);
     update(node*2+1,m+1,e,i,j);
}     
big query(big node,big b,big e,big i)    
{
     if(i<b || i>e)
         return 0;
         if(b==e)
         {
                 if(i==b)
                 return F[node];
                 else
                 return 0;
         }
     big m=(b+e)/2;
     big r1=query(node*2,b,m,i);
     big r2=query(node*2+1,m+1,e,i);
     return F[node]+r1+r2;
}  
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    big n,q,i,j;
    big sum;
    while(scanf("%I64d %I64d",&n,&q)==2)
    {
        CLR(F);
        for(i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        for(i=1;i<=q;i++)
        {
            scanf("%I64d %I64d",&q1[i],&q2[i]);
            update(1,1,n,q1[i],q2[i]);
        }
        for(i=1;i<=n;i++)
        {
           v[i]=query(1,1,n,i);
        }
        sort(v+1,v+n+1);
        sort(a+1,a+n+1);
        sum=0;
        for(i=n;i>0 && v[i];i--)
            sum+=a[i]*v[i];
        printf("%I64d\n",sum);      
    }
    return 0;
}
