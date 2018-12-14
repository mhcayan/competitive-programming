#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#define CLR(a) memset(a,0,sizeof(a))
using namespace std;
int pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int factor(int num,int ff[])
{
	int n,m,i,c;
	n=num;
	m=sqrt(n);
	c=0;
	for(i=0;pr[i]<=m;i++)
	{
		if(n%pr[i]==0)
		{
			ff[c++]=pr[i];
			while(n%pr[i]==0)
				n/=pr[i];
			m=sqrt(n);
		}
	}
	if(n>1 && n<num)
		ff[c++]=n;
	return c;
}
int main()
{
	int cas,d,s,t,u,v,i,dis[1005],q[2000],front,rear,f[1000],c;
	bool vis[1500],flag;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%d %d",&s,&d);
		if(s==d)
			printf("Case %d: 0\n",t);
		else
		{
		CLR(vis);
		front=rear=0;
		q[front]=s;
		dis[s]=0;
		flag=0;
		while(front<=rear)
		{
			u=q[front++];
			c=factor(u,f);
			for(i=0;i<c;i++)
			{
				v=u+f[i];
				if(v<=d)
				{
					if(vis[v]==0)
					{
					    dis[v]=1+dis[u];
					    if(v==d)
						{
						    flag=1;
						    break;
						}
					    vis[v]=1;
						q[++rear]=v;
					}
				}
				else
					break;
			}
			if(flag)
				break;
		}
		if(flag)
			printf("Case %d: %d\n",t,dis[d]);
		else
			printf("Case %d: -1\n",t);
		}
	}
	return 0;
}