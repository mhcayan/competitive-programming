#include<cstdio>
#include<vector>
using namespace std;
int F[300000000],Flag[300000000],tc;
void build(int n,int b,int e,int i,int j)    
{
     if(i>e || j<b)
         return;
     if(i<=b && e<=j)
     {
         if(Flag[n]!=tc)
         {
             Flag[n]=tc;
             F[n]=1;
             return;
         }
         F[n]++;
         return;
     }
     int m=(b+e)/2;
     build(2*n,b,m,i,j);
     build(2*n+1,m+1,e,i,j);
}
int qry(int n,int b,int e,int v)
{
    if(v<b || v>e)
        return 0;
    if(b==e)
        return F[n];
    int m;
    m=(b+e)/2;
    return F[n]+qry(2*n,b,m,v)+qry(2*n+1,m+1,e,v);
}
int main()
{
    int cas,n,q,v,i,j;
    scanf("%d",&cas);
    for(tc=1;tc<=cas;tc++)
    {
        scanf("%d %d",&n,&q);
        while(n--)
        {
            scanf("%d %d",&i,&j);
            build(1,0,100000000,i,j);
        }
        printf("Case %d:\n",tc);
        while(q--)
        {
            scanf("%d",&v);
            printf("%d\n",qry(1,0,100000000,v));
        }
    }
    return 0;
}
