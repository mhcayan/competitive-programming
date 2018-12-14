#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
const int inf=2000000000;
int n,list[50],vis[50];
void dfs(int u,int size)
{
	if(!vis[u])
	{
		vis[u]=1;
		list[size]=u;
		for(int i=1;i<=n;i++)
			dfs(i,size+1);
		if(size==n)
		{
			for(i=1;i<=n;i++)
				printf("%d",list[i]);
			printf("\n");
		}
		vis[u]=0;
	}
}

int main()
{
	int i;
    while(scanf("%d",&n)==1)
    {
		CLR(vis);
		for(i=1;i<=n;i++)
	        dfs(i,1);
    }
    return 0;
}
