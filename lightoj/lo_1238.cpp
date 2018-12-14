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
//const int inf=2000000000;
typedef struct{
	int x,y;
}state;
char a[25][25];
int xx[4]={-1,0,1,0},yy[4]={0,1,0,-1},dis[25][25];
int bfs(state s)
{
	int i,c;
	state u,v;
	queue<state>q;
	q.push(s);
	a[s.x][s.y]='#';
	dis[s.x][s.y]=0;
	c=0;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			v.x=u.x+xx[i];
			v.y=u.y+yy[i];
			if(a[v.x][v.y]=='.')
			{
				a[v.x][v.y]='#';
				dis[v.x][v.y]=1+dis[u.x][u.y];
				q.push(v);
			}
			else if(a[v.x][v.y]=='a' || a[v.x][v.y]=='b' || a[v.x][v.y]=='c')
			{
				c++;
				dis[v.x][v.y]=1+dis[u.x][u.y];
				if(c==3)
					break;
				a[v.x][v.y]='#';
				q.push(v);
			}
		}
		if(c==3)
			break;
	}
	return dis[v.x][v.y];
}
int main()
{
	int cas,t,r,c,i,j;
	bool flag;
	state s;
	scanf("%d",&cas);
    for(t=1;t<=cas;t++)
    {
		scanf("%d %d",&r,&c);
		getchar();
		for(i=0;i<r;i++)
			gets(a[i]);
		flag=0;
		for(i=0;i<r;i++)
		{
			for(j=0;a[i][j];j++)
			{
				if(a[i][j]=='h')
				{
					flag=1;
					s.x=i,s.y=j;
					break;
				}
			}
			if(flag)
				break;
		}
		printf("Case %d: %d\n",t,bfs(s));
    }
    return 0;
}
