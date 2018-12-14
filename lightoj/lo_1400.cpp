#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iterator>
using namespace std;
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
int main()
{
	int cas,tc,n,st[102],em[102][102],co[102][102],mrg[102],i,j,val,m,f;
	queue<int>q;
	scanf("%d",&cas);
	for(tc=1;tc<=cas;tc++)
    {
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			q.push(i);
			st[i]=1;
			mrg[i]=0;
			for(j=1;j<=n;j++)
			{
				scanf("%d",&val);
				em[i][j]=val-n;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&val);
				co[i][val]=j;
			}
		}
		while(!q.empty())
		{
			m=q.front();
			q.pop();
			while(1)
			{
				f=em[m][st[m]++];
				if(mrg[f]==0)
				{
					mrg[f]=m;
					break;
				}
				else if(co[f][mrg[f]]>co[f][m])
				{
					q.push(mrg[f]);
					mrg[f]=m;
					break;
				}
			}
		}
		printf("Case %d: ",tc);
        for(i=1;i<n;i++)
		    printf("(%d %d) ",mrg[i],i+n);
		printf("(%d %d)\n",mrg[n],n+n);
	}
    return 0;
}
