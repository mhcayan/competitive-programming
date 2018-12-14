#include<cstdio>
using namespace std;
int F[300005];
void init(int n,int b,int e)
{
    if(b==e)
    {
        F[n]=1;
        return;
    }
    int m=(b+e)/2;
    init(n*2,b,m);
    init(n*2+1,m+1,e);
    F[n]=F[2*n]+F[2*n+1];
}
int qry(int n,int b,int e,int t,int v)
{
    if(b==e)
    {
        F[n]=0;
        return b;
    }    
    int m=(b+e)/2;
    int r;
    if(t+F[2*n+1]>v)
        r=qry(n*2+1,m+1,e,t,v);
    else
        r=qry(n*2,b,m,t+F[n*2+1],v);
    F[n]--;
    return r;
}
int main()
{
    int cas,tc,n,i,g[100005],r;
    scanf("%d",&cas);
    for(tc=1;tc<=cas;tc++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&g[i]);
        init(1,1,n);
        for(i=n;i>1;i--)
            r=qry(1,1,n,0,g[i]);
        r=qry(1,1,n,0,g[1]);
        printf("Case %d: %d\n",tc,r);
    }
    return 0;
}
