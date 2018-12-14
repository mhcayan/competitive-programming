//special thanks fahim vai
#include<cstdio>
#include<cmath>
#include<vector>
#define CLR(a) memset(a,0,sizeof(a))
using namespace std;
int main()
{
	int a[100][100],taken[100],list[100],indeg[100],n,e,i,j,k,invalid,u,v;
	while(scanf("%d %d",&n,&e)==2)
	{
		invalid=0;
		CLR(a);
		CLR(indeg);
		CLR(taken);
		while(e--)
		{
		    scanf("%d %d",&u,&v);
			a[u][v]=1;
			indeg[v]++;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(!indeg[j] && !taken[j])
				{
					taken[j]=1;
					list[i]=j;
					for(k=1;k<=n;k++)
					{
						if(a[j][k] && !taken[k])
							indeg[k]--;
					}
					break;
				}
			}
			if(j>n)
			{
				invalid=1;
				break;
			}
		}
		if(invalid)
			printf("invalid\n");
		else
		{
		    for(i=1;i<=n;i++)
				printf("%d ",list[i]);
			printf("\n");
		}
	}
	return 0;
}


