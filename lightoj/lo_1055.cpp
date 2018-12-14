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
using namespace std;
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
int xx[]={0,-1,0,1},yy[]={-1,0,1,0},dis[9][9][9][9][9][9],n;
char a[12][12],aa[12][12];
struct st
{
       int ax,ay,bx,by,cx,cy;
};
bool valid(int i,int j)
{
     if(i<0||j<0||i==n||j==n)
         return 0;
     return 1;
}
bool canmove(int x,int y,int i)
{
     int nx,ny;
     nx=x+xx[i];
     ny=y+yy[i];
     //cout<<x<<' '<<y<<' '<<nx<<' '<<ny<<endl;
     if(valid(nx,ny))
     {
         if(a[nx][ny]=='#')
             return 0;
         if(a[nx][ny]=='.' || a[nx][ny]=='X')
             return 1;
         return canmove(nx,ny,i);
     }
     return 0;
}     
int bfs(st s)
{
    st u,v;
    queue<st>q;
    int i;
    dis[s.ax][s.ay][s.bx][s.by][s.cx][s.cy]=1;
    //cout<<s.ax<<' '<<s.ay<<' '<<s.bx<<' '<<s.by<<' '<<s.cx<<' '<<s.cy<<endl;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            if(canmove(u.ax,u.ay,i))
            {
                v.ax=u.ax+xx[i],v.ay=u.ay+yy[i];
                a[u.ax][u.ay]='.';
                a[v.ax][v.ay]='A';
            }
            else
            {
                v.ax=u.ax,v.ay=u.ay;
            }
            if(canmove(u.bx,u.by,i))
            {
                v.bx=u.bx+xx[i],v.by=u.by+yy[i];
                a[u.bx][u.by]='.';
                a[v.bx][v.by]='B';
            }
            else
            {
                v.bx=u.bx,v.by=u.by;
            }
            if(canmove(u.cx,u.cy,i))
            {
                v.cx=u.cx+xx[i],v.cy=u.cy+yy[i];             
                a[u.cx][u.cy]='.';
                a[v.cx][v.cy]='C';
            }
            else
            {
                v.cx=u.cx,v.cy=u.cy;
            }
            cout<<v.ax<<' '<<v.ay<<' '<<v.bx<<' '<<v.by<<' '<<v.cx<<' '<<v.cy<<endl;
            if(dis[v.ax][v.ay][v.bx][v.by][v.cx][v.cy]==0)
            {
                dis[v.ax][v.ay][v.bx][v.by][v.cx][v.cy]=1+dis[u.ax][u.ay][u.bx][u.by][u.cx][u.cy];
                if(aa[v.ax][v.ay]=='X'&&aa[v.bx][v.by]=='X'&&aa[v.cx][v.cy]=='X')
                {
                    cout<<v.ax<<' '<<v.ay<<' '<<v.bx<<' '<<v.by<<' '<<v.cx<<' '<<v.cy<<endl;
                    return dis[v.ax][v.ay][v.bx][v.by][v.cx][v.cy];
                }
                q.push(v);
            }
        }
    }
    return -1;
}            
int main()
{
    int cas,tc,i,j,ans;
    st s;
    scanf("%d",&cas);
    for(tc=1;tc<=cas;tc++)
    {
        scanf("%d\n",&n);
        for(i=0;i<n;i++)
        {
            gets(a[i]);
            for(j=0;a[i][j];j++)
            {
                aa[i][j]=a[i][j];
                if(a[i][j]!='.')
                {
                    if(a[i][j]=='A')
                        s.ax=i,s.ay=j;
                    else if(a[i][j]=='B')
                        s.bx=i,s.by=j;
                    else if(a[i][j]=='C')
                        s.cx=i,s.cy=j;
                }
            }
        }  
        CLR(dis);
        ans=bfs(s);
        if(ans==-1)
            printf("Case %d: trapped\n",tc);
        else
            printf("Case %d: %d\n",tc,ans-1);
    }
    return 0;
}
