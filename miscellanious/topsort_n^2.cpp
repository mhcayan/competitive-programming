#include<stdio.h>
#include<string.h>
int main()
{
	long a[100][100],taken[100],list[100],indeg[100],i,j,k,p,q,e,v,invalid;
	while(scanf("%ld %ld",&v,&e)==2)
	{
		memset(a,0,sizeof(a));
		memset(indeg,0,sizeof(indeg));
		memset(taken,0,sizeof(taken));
		for(i=0;i<e;i++)
		{
			scanf("%d %d",&p,&q);
			a[p][q]=1;
			indeg[q]++;
		}
		invalid=0;
		for(i=1;i<=v;i++)
		{
			for(j=1;j<=v;j++)
			{
				if(taken[j]==0 && indeg[j]==0)
				{
					taken[j]=1;
					list[i]=j;
					for(k=1;k<=v;k++)
					{
						if(a[j][k])
							indeg[k]--;
					}
					break;
				}
				
			}
			if(j>v)
			{
				invalid=1;
				break;
			}
		}
		if(invalid)
			printf("-1\n");
		else
		{
			for(i=1;i<=v;i++)
				printf("%ld ",list[i]);
		}
	}
	return 0;
}


