#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
#define CLR(a) memset(a,0,sizeof(a))
const int inf=2000000000;
char a[505][505];
int vis[505][505],total[100000],xx[4]={-1,0,1,0},yy[4]={0,1,0,-1},m,n;
int bfs(int s1,int s2,int mark)
{
	int c=0,u,v,x,y,i,q1[250500],q2[250500],front=1,rear=1;
	vis[s1][s2]=mark;
	q1[front]=s1;
	q2[front]=s2;
	while(front<=rear)
	{
		u=q1[front];
		v=q2[front++];
		for(i=0;i<4;i++)
		{
			x=u+xx[i];
			y=v+yy[i];
			if(x>=0 && y>=0 && x<m && y<n && vis[x][y]==0)
			{
				vis[x][y]=mark;
				if(a[x][y]=='C')
					c++;
				q1[++rear]=x;
				q2[rear]=y;
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

