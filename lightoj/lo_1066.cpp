#include<cstdio>
#include<queue>
using namespace std;
typedef struct{
	int x,y;
}node;
char a[12][12];
int xx[4]={-1,0,1,0},yy[4]={0,1,0,-1};
node s;
int bfs(int n)
{
	bool flag=0;
	int i,dis[12][12];
	node u,v;
	queue<node>q;
	q.push(s);
	dis[s.x][s.y]=0;
	while(!q.empty())
	{	
		u=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			v.x=u.x+xx[i],v.y=u.y+yy[i];
			if(v.x>=0 && v.y>=0 && v.x<n && v.y<n)
			{
				if(a[v.x][v.y]=='.' || (a[v.x][v.y]>='A' && a[v.x][v.y]<a[s.x][s.y]))
				{
					a[v.x][v.y]=a[s.x][s.y];
					dis[v.x][v.y]=1+dis[u.x][u.y];
					q.push(v);
				}
				else if(a[v.x][v.y]==a[s.x][s.y]+1)
				{
					dis[v.x][v.y]=1+dis[u.x][u.y];
					s.x=v.x,s.y=v.y;
					flag=1;
					break;
				}
			}
		}
		if(flag)
			break;
	}
	if(flag)
	    return dis[s.x][s.y];
	else
		return 0;
}
int main()
{
	int cas,t,n,i,j,total,c,l;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%d",&n);
		getchar();
		c=0;
		for(i=0;i<n;i++)
		{
			gets(a[i]);
			for(j=0;j<n;j++)
			{
				if(a[i][j]>='A' && a[i][j]<='Z')
				{
					c++;
					if(a[i][j]=='A')
						s.x=i,s.y=j;
				}
			}
		}
		total=0;
		for(i=1;i<c;i++)
		{
			l=bfs(n);
			if(l==0)
				break;
			total+=l;
		}
		if(c==i)
			printf("Case %d: %d\n",t,total);
		else
			printf("Case %d: Impossible\n",t);
	}
			
	return 0;
}