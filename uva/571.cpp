#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#define CLR(a) memset(a,0,sizeof(a))
using namespace std;
typedef struct{
	int a,b;
}state;
state par[1005][1005];
bool vis[1005][1005];
int work[1005][1005];
void print(state u)
{
	if(u.a==0 && u.b==0)
		return;
	print(par[u.a][u.b]);
	if(work[u.a][u.b]==1)
		printf("fill A");
	else if(work[u.a][u.b]==2)
		printf("fill B");
	else if(work[u.a][u.b]==3)
		printf("empty A");
	else if(work[u.a][u.b]==4)
		printf("empty B");
	else if(work[u.a][u.b]==5)
		printf("pour A B");
	else
		printf("pour B A");
	printf("\n");
}
void bfs(state c,int n)
{
	state u,v;
	queue<state>q;
	vis[0][0]=1;
	u.a=0;
	u.b=0;
	q.push(u);
	while(!q.empty())
	{
		u=q.front();
		if(u.b==n)
			break;
		q.pop();
		//fill a
		v.a=c.a;
		v.b=u.b;
		if(vis[v.a][v.b]==0)
		{
			par[v.a][v.b]=u;
			vis[v.a][v.b]=1;
			work[v.a][v.b]=1;
			q.push(v);
		}
		//fill b
		v.a=u.a;
		v.b=c.b;
		if(vis[v.a][v.b]==0)
		{
			par[v.a][v.b]=u;
			vis[v.a][v.b]=1;
			work[v.a][v.b]=2;
			q.push(v);
		}
		//empty a
		v.a=0;
		v.b=u.b;
		if(vis[v.a][v.b]==0)
		{
			par[v.a][v.b]=u;
			vis[v.a][v.b]=1;
			work[v.a][v.b]=3;
			q.push(v);
		}
		//empty b
		v.a=u.a;
		v.b=0;
		if(vis[v.a][v.b]==0)
		{
			par[v.a][v.b]=u;
			vis[v.a][v.b]=1;
			work[v.a][v.b]=4;
			q.push(v);
		}
		//pour a->b
		v.b=u.b+u.a;
		v.a=0;
		if(v.b>c.b)
		{
			v.a=v.b-c.b;
			v.b=c.b;
		}
		if(vis[v.a][v.b]==0)
		{
			par[v.a][v.b]=u;
			vis[v.a][v.b]=1;
			work[v.a][v.b]=5;
			q.push(v);
		}
		//pour b->a
		v.a=u.a+u.b;
		v.b=0;
		if(v.a>c.a)
		{
			v.b=v.a-c.a;
			v.a=c.a;
		}
		if(vis[v.a][v.b]==0)
		{
			par[v.a][v.b]=u;
			vis[v.a][v.b]=1;
			work[v.a][v.b]=6;
			q.push(v);
		}
	}
	print(u);
}		
int main()
{
	state c;
	int n;
	while(scanf("%d %d %d",&c.a,&c.b,&n)==3)
	{
		CLR(vis);
		bfs(c,n);
		printf("success\n");
	}
	return 0;
}