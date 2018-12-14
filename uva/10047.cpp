#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#define CLR(a) memset(a,0,sizeof(a));
using namespace std;
typedef struct{
	int x,y,cl,dr;
}state;
int vis[30][27][9][9],dis[30][27][9][9];
void bfs(state s,state d,int m,int n)
{
	state u,v;
	bool flag=0;
	queue<state>q;
	q.push(s);
	dis[s.x][s.y][s.cl][s.dr]=0;
	while(!q.empty())
	{
		u=q.front();
		if(u.x==d.x && u.y==d.y && u.cl==d.cl)
		{
			flag=1;
			break;
		}
		q.pop();
		//move forward
		if(u.dr==0)
		{
			v.x=u.x-1;
			v.y=u.y;
		}
		else if(u.dr==1)
		{
			v.x=u.x;
			v.y=u.y+1;
		}
		else if(u.dr==2)
		{
			v.x=u.x+1;
			v.y=u.y;
		}
		else
		{
			v.x=u.x;
			v.y=u.y-1;
		}
		v.cl=u.cl+1;
		if(v.cl==5)
			v.cl=0;
		v.dr=u.dr;
		if(v.x>=1 && v.x<=m && v.y>=1 && v.y<=n)
		{
			if(vis[v.x][v.y][v.cl][v.dr]==0)
			{
			    q.push(v);
			    dis[v.x][v.y][v.cl][v.dr]=1+dis[u.x][u.y][u.cl][u.dr];
				vis[v.x][v.y][v.cl][v.dr]=1;
			}
		}
		//turn right
		v.x=u.x;
		v.y=u.y;
		v.cl=u.cl;
		v.dr=u.dr+1;
		if(v.dr>3)
			v.dr=0;
		if(vis[v.x][v.y][v.cl][v.dr]==0)
		{
		    q.push(v);
		    dis[v.x][v.y][v.cl][v.dr]=1+dis[u.x][u.y][u.cl][u.dr];
			vis[v.x][v.y][v.cl][v.dr]=1;
		}
		v.dr=u.dr-1;
		if(v.dr<0)
			v.dr=0;
    	if(vis[v.x][v.y][v.cl][v.dr]==0)
		{
		    q.push(v);
		    dis[v.x][v.y][v.cl][v.dr]=1+dis[u.x][u.y][u.cl][u.dr];
			vis[v.x][v.y][v.cl][v.dr]=1;
		}
	}
	if(flag)
		printf("minimum time = %d sec\n",dis[u.x][u.y][u.cl][u.dr]);
	else
		printf("destination not reachable\n");
}
int main()
{
	char str[1005];
	int m,n,i,j,k,l,t=1;
	state s,d;
	while(scanf("%d %d",&m,&n))
	{
		if(m==0 && n==0)
			break;
		CLR(vis)
		getchar();
		for(i=1;i<=m;i++)
		{
			gets(str);
			for(j=0;j<n;j++)
			{
				if(str[j]=='#')
				{
					for(k=0;k<5;k++)
						for(l=0;l<4;l++)
					        vis[i][j+1][k][l]=1;
				}
				else if(str[j]=='S')
				{
					vis[i][j+1][0][0]=1;
					s.x=i,s.y=j+1,s.cl=0,s.dr=0;
				}
				else if(str[j]=='T')
				{
					d.x=i,d.y=j+1,d.cl=0;
				}
			}
		}
		if(t>1)
			printf("\n");
		printf("Case #%d\n",t++);
		bfs(s,d,m,n);
	}
	return 0;
}


