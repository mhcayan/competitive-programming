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
char a[13][13];
int dis[12][12],vis[12][12],K,m,n,xx[]={-1,-2,-2,-1,1,2,2,1},yy[]={-2,-1,1,2,2,1,-1,-2};
typedef struct{
	int x,y;
}node;
int bfs(int i,int j,int kk)
{
	int k,total;
	node s,u,v;
	s.x=i,s.y=j;
	queue<node>q;
	q.push(s);
	k=0;
	if(a[s.x][s.y]>='0' && a[s.x][s.y]<='9')
		k=1;
	total=0;
	dis[s.x][s.y]=0;
	vis[s.x][s.y]=kk;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<8;i++)
		{
			v.x=u.x+xx[i];
			v.y=u.y+yy[i];
			if(v.x>=0 && v.y>=0 && v.x<m && v.y<n)
			{
				if(vis[v.x][v.y]!=kk)
				{
					vis[v.x][v.y]=kk;
					dis[v.x][v.y]=1+dis[u.x][u.y];
					if(a[v.x][v.y]>'0' && a[v.x][v.y]<='9')
					{
						k++;
						total+=(dis[v.x][v.y]+a[v.x][v.y]-'0'-1)/(a[v.x][v.y]-'0');
					}
					q.push(v);
				}
			}
		}
	}
	if(k==K)
		return total;
	return inf;
}
int main()
{
	int cas,tc,i,j,min,total,kk;
	scanf("%d",&cas);
	for(tc=1;tc<=cas;tc++)
    {
		scanf("%d %d\n",&m,&n);
		K=0;
		for(i=0;i<m;i++)
		{
			gets(a[i]);
			for(j=0;j<n;j++)
			{
				if(a[i][j]>='1' && a[i][j]<='9')
					K++;
			}
		}
		min=inf;
		kk=1;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
			    total=bfs(i,j,kk++);
				if(total<min)
				{
					min=total;
				}
			}
		}
		if(min==inf)
			min=-1;
		printf("Case %d: %d\n",tc,min);
    }
    return 0;
}
