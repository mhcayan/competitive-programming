#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#define CLR(a) memset(a,0,sizeof(a))
#define pb push_back
using namespace std;
int col[20005],mark[20005];
int main()
{
	int cas,t,n,u,v,pos,neg,total,i,c,s;
	vector<int>edge[20005];
	queue<int>q;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%d",&n);
		c=1;
		while(n--)
		{
			scanf("%d %d",&u,&v);
			if(mark[u]==0)
				mark[u]=c++;
			if(mark[v]==0)
				mark[v]=c++;
			edge[mark[u]].pb(mark[v]);
			edge[mark[v]].pb(mark[u]);
		}
		total=0;
		for(s=1;s<c;s++)
		{
			if(col[s]==0)
			{
				pos=0,neg=0;
				q.push(s);
				col[s]=1;
				pos++;
				while(!q.empty())
				{
					u=q.front();
					q.pop();
					for(i=0;i<edge[u].size();i++)
					{
						v=edge[u][i];
						if(col[v]==0)
						{
							col[v]=-col[u];
							if(col[v]==1)
								pos++;
							else
								neg++;
							q.push(v);
						}
					}
				}
				total+=(pos>neg?pos:neg);
			}
		}
		printf("Case %d: %d\n",t,total);
		if(t<cas)
		{
			CLR(mark);
		    for(i=1;i<c;i++)
			{
				col[i]=0;
			    edge[i].clear();
			}
		}
	}
	return 0;
}

