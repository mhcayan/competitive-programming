#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<iterator>
using namespace std;
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
int xx[4]={-1,0,1,0},yy[4]={0,1,0,-1},fire[220][220],dis[220][220],r,c;
char a[220][220];
typedef struct{
	int x,y;
}state;
const int inf=2000000000;
void fbfs(state s)
{
	state u,v;
	int i;
	queue<state>q;
	q.push(s);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			v.x=u.x+xx[i];
			v.y=u.y+yy[i];
			if(v.x>=0 && v.x<r && v.y>=0 && v.y<c)
			{
			    if(a[v.x][v.y]!='#' && fire[v.x][v.y]>1+fire[u.x][u.y])
				{
					fire[v.x][v.y]=1+fire[u.x][u.y];
					q.push(v);
				}
			}
		}
	}
}
int bfs(state s)
{
	state u,v;
	int i;
	queue<state>q;
	bool flag=0;
	q.push(s);
	dis[s.x][s.y]=0;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			v.x=u.x+xx[i];
			v.y=u.y+yy[i];
			if(v.x<0 || v.x==r || v.y<0 || v.y==c)
			{
				flag=1;
				break;
			}
			if(a[v.x][v.y]!='#' && 1+dis[u.x][u.y]<fire[v.x][v.y])
			{
				a[v.x][v.y]='#';
				dis[v.x][v.y]=1+dis[u.x][u.y];
				q.push(v);
			}
		}
		if(flag)
			break;
	}
	if(!flag)
		return -1;
	return 1+dis[u.x][u.y];
}
int main()
{
	int cas,t,i,j,man;
	queue<state>q;
	state f,s;
    scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		scanf("%d %d",&r,&c);
		getchar();
		for(i=0;i<r;i++)
		{
			scanf("%s",a[i]);
			getchar();
			for(j=0;j<c;j++)
			{
				if(a[i][j]=='F')
				{
					f.x=i;
					f.y=j;
					q.push(f);
					fire[i][j]=0;
				}
				else
				{
					if(a[i][j]=='J')
						s.x=i,s.y=j;
					fire[i][j]=inf;
				}
			}
		}
		while(!q.empty())
		{
			fbfs(q.front());
			q.pop();
		}
		
		man=bfs(s);
		if(man==-1)
			printf("Case %d: IMPOSSIBLE\n",t);
		else
			printf("Case %d: %d\n",t,man);
    }
    return 0;
}
