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
#define ulong unsigned long
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
int a[100005],m[300000];
void init(int node,int b,int e)
{
     if(b==e)
         m[node]=a[b];
     else
     {
         int mid=(b+e)/2;
         init(node*2,b,mid);
         init(node*2+1,mid+1,e);
         m[node]=m[node*2]+m[node*2+1];
     }
}
void add(int node,int b,int e,int i,int v)
{
     if(i>=b && i<=e)
     {
         m[node]+=v;
         if(b==e)
             return;
         int mid=(b+e)/2;
         add(node*2,b,mid,i,v);
         add(node*2+1,mid+1,e,i,v);
     }
}
         
int query(int node,int i,int j,int b,int e)        
{
    if(b>j || e<i)
        return -1;
    if(i<=b && e<=j)
        return m[node];
    int mid=(b+e)/2;
    int p=query(node*2,i,j,b,mid);
    int q=query(node*2+1,i,j,mid+1,e);
    if(p==-1)
        return q;
    if(q==-1)
        return p;
    return p+q;
}
int main()
{
    int cas,tc,n,q,qn,i,j,v;
    scanf("%d",&cas);
    for(tc=1;tc<=cas;tc++)
    {
        scanf("%d %d",&n,&q);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        init(1,0,n-1);
        printf("Case %d:\n",tc);
        while(q--)
        {
            scanf("%d",&qn);
            if(qn==1)
            {
                scanf("%d",&i);
                printf("%d\n",a[i]);
                add(1,0,n-1,i,-a[i]);
                a[i]=0;
            }
            else if(qn==2)
            {
                 scanf("%d %d",&i,&v);
                 a[i]+=v;
                 add(1,0,n-1,i,v);
            }
            else
            {
                scanf("%d %d",&i,&j);
                printf("%d\n",query(1,i,j,0,n-1));
            }
        }
    }
    return 0;
}
