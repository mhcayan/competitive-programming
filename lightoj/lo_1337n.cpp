#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
#define CLR(a) memset(a,0,sizeof(a))
typedef struct{
	int x,y;
}state;
char a[505][505];
int vis[505][505],total[50000],xx[4]={-1,0,1,0},yy[4]={0,1,0,-1},m,n;
int bfs(int x,int y,int mark)
{
	int c=0,i;
	state u,v;
	u.x=x,u.y=y;
	queue<state>q;
	q.push(u);
	vis[u.x][u.y]=mark;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			v.x=u.x+xx[i];
			v.y=u.y+yy[i];
			if(v.x>=0 && v.y>=0 && v.x<m && v.y<n && vis[v.x][v.y]==0)
			{
				vis[v.x][v.y]=mark;
				if(a[v.x][v.y]=='C')
					c++;
				q.push(v);
			}
		}
	}
	return c;
}

int main()
{
	int cas,t,q,i,j,mark,x,y;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%d %d %d",&m,&n,&q);
		getchar();
		for(i=0;i<m;i++)
		{
			gets(a[i]);
			for(j=0;j<n;j++)
			{
				if(a[i][j]=='#')
					vis[i][j]=1;
				else
					vis[i][j]=0;
			}
		}
		mark=1;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				if(a[i][j]=='.' && vis[i][j]==0)
				{
					total[mark]=bfs(i,j,mark);
					mark++;
				}
		}
		printf("Case %d:\n",t);
		while(q--)
		{
			scanf("%d %d",&x,&y);
			printf("%d\n",total[vis[x-1][y-1]]);
		}
	}
	return 0;
}

