#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<time.h>
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define RFOR(i,a,b) for(i=a;i>=b;i--)
#define MAXSERVER 500
#define MAXREPLICA 200
#define MAXL 500
#define INT_MX 2147483647
#define mems(x,a) memset(x,a,sizeof(x))

typedef vector<int> vi;

inline int MIN(int a,int b){ return (a>b)?b:a;}

void Convert_To_Binary_Tree();
int Replica_Placement(int,int,int,int);

int dp[MAXSERVER][MAXREPLICA][MAXL];
int S,R,Dummy,Read[MAXSERVER];
vi adj[MAXSERVER],cst[MAXSERVER];
long long call;
int a,b,p;

int rando()
{
    return p=(a*p+b)%51;
}
int main()
{
    freopen("input_file2.txt","r",stdin);
    freopen("output_dp2.txt","w",stdout);
    int e,i,u,v,c,j,cas,weight;
        time_t t;
        scanf("%d",&cas);
        printf("%d\n",cas);
  //  srand(1);
    
   // printf("Enter Number Of Total Server And Replica To be Placed:\n");
   while(cas--)
   {
    scanf("%d %d",&S,&R);
    
    //printf("For Each Server,Enter Number Of Request:\n");
    /*FOR(i,1,S) scanf("%d",&Read[i]);
    printf("Randomly Assigning Request per Server:\n");*/
    a=3,b=2,p=5;
    FOR(i,1,S)
     scanf("%d",&Read[i]);
    e=S-1;
    
   // printf("For Each Connection,Enter [node_u node_v cost(will be generated randomly)]\n"); 
    //srand((unsigned) time(&t));
    while(e--)
    {
      scanf("%d %d %d",&u,&v,&weight);
      adj[u].pb(v);
      cst[u].pb(weight);
    }
    Dummy=S+1;
    Convert_To_Binary_Tree();
   /* printf("%d\n",Dummy);
    FOR(i,1,9)
    {
     printf("Node %d er (pola,cost):",i);
     for(j=0;j<adj[i].size();j++)
      printf(" (%d,%d)",adj[i][j],cst[i][j]);
     printf("Ei Node er Read=%d\n",Read[i]);
    }*/
    //call=0;
   float start,end;
    mems(dp,-1);
    //start=clock();
    //call=0;
    printf("%d\n",Replica_Placement(1,R,0,0));
    //end=clock();
    //printf("Total Call:%lld\nTotal Time=%f",call,end-start);
   }
    getchar();getchar();
    return 0;
}

int Replica_Placement(int v,int k,int l,int c)
{
    //call++;
    int &rs=dp[v][k][l];
    if(rs!=-1) return rs;
    int i,L,r;
    rs=INT_MX;
    if(v==1)
    {
        for(i=0;i<k;i++){
            rs=MIN(rs,Replica_Placement(adj[v][0],i,1,cst[v][0])+Replica_Placement(adj[v][1],k-i-1,1,cst[v][1]));
         //   printf("(Left=%d,Right=%d)==>%d+%d=%d\n",i,k-i-1,L,r,L+r);
        }
        return rs;
    }
    if(adj[v].size()==0)
    {
        if(k)
         return rs=0;
        return rs=(Read[v]*c);
    } 
    if(v<=S)
    {
        for(i=0;i<k;i++)
         rs=MIN(rs,Replica_Placement(adj[v][0],i,1,cst[v][0])+Replica_Placement(adj[v][1],k-i-1,1,cst[v][1]));
    }
    for(i=0;i<=k;i++)
      rs=MIN(rs,Read[v]*c+Replica_Placement(adj[v][0],i,l+1,c+cst[v][0])+Replica_Placement(adj[v][1],k-i,l+1,c+cst[v][1]));
   return rs;   
}

void Convert_To_Binary_Tree()
{
    int i,j,u,sz;
    
    FOR(i,1,S)
    {
        sz=adj[i].size();
        if(sz==1)
        {
            Read[Dummy]=0;
            adj[i].pb(Dummy);
            cst[i].pb(0);
            Dummy++;
        }
        else if(sz>2)
        {
            u=i;
            FOR(j,2,sz-1)
            {
               Read[Dummy]=0;
               adj[u].pb(Dummy);
               cst[u].pb(0);
               adj[u].pb(adj[i][j]);
               cst[u].pb(cst[i][j]);
               adj[i].erase(adj[i].begin()+j);
               cst[i].erase(cst[i].begin()+j);
               u=Dummy++;   
            }
              adj[u].pb(adj[i][1]);
              cst[u].pb(cst[i][1]);
              adj[i].erase(adj[i].begin()+1);
              cst[i].erase(cst[i].begin()+1);
              adj[u].pb(adj[i][0]);
              cst[u].pb(cst[i][0]);
              adj[i].erase(adj[i].begin()+0);
              cst[i].erase(cst[i].begin()+0);
        }
    }
}
