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
const int inf=2000000000;
int cs,n,i,val,j,m,f,wo[502][502],ma[502][502],mr[502],st[502];
int main()
{
	queue<int>q;
	scanf("%d",&cs);
	while(cs--)
    {
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			mr[i]=0;
			for(j=0;j<=n;j++)
			{
				scanf("%d",&val);
				wo[i][val]=j;
			}
		}
		for(i=1;i<=n;i++)
		{
			q.push(i);
			st[i]=1;
			for(j=0;j<=n;j++)
				scanf("%d",&ma[i][j]);
		}
		while(!q.empty())
		{
			m=q.front();
			q.pop();
			for(i=st[m];i<=n;i++)
			{
				f=ma[m][i];
				if(mr[f]==0)
				{
					mr[f]=m;
					st[m]=i+1;
					break;
				}
				else if(wo[f][mr[f]]>wo[f][m])
				{
					q.push(mr[f]);
					mr[f]=m;
					st[m]=i+1;
					break;
				}
			}
		}
		for(i=1;i<=n;i++)
			printf("%d %d\n",mr[i],i);

    }
    return 0;
}
