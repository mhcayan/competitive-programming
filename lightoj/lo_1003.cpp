#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<string>
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
const int inf=2000000000;
int invalid,vis[11000];
vector<int>node[11000];
void dfs(int u)
{
	if(invalid || vis[u]==2)
		return;
	if(vis[u]==1)
	{
		invalid=1;
		return;
	}
	vis[u]=1;
	for(int i=0;i<node[u].size();i++)
		dfs(node[u][i]);
	vis[u]=2;
}
int main()
{
	map<string,int>name;
	int cas,t,c,p,q,i,m;
	string s1,s2;
	scanf("%d",&cas);
    for(t=1;t<=cas;t++)
    {
		c=0;
		scanf("%d",&m);
		getchar();
		while(m--)
		{
			cin>>s1>>s2;
			if(name.find(s1)==name.end())
				name[s1]=c++;
			if(name.find(s2)==name.end())
				name[s2]=c++;
			p=name[s1];
			q=name[s2];
			node[p].pb(q);
		}
		for(i=0;i<c;i++)
		{
			if(vis[i]==0 && !invalid)
				dfs(i);
		}
		printf("Case %d: ",t);
		if(invalid)
			printf("No\n");
		else
			printf("Yes\n");
		if(t<cas)
		{
			invalid=0;
			name.clear();
		    for(i=0;i<c;i++)
			{
				node[i].clear();
			    vis[i]=0;
			}
		}
    }
    return 0;
}
