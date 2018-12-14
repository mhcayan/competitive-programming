#include<stdio.h>
int main()
{
	int m,n,alct[1000],par[10000],temp[1000],i,j,p[1000],best,worst;
	while(1)
	{
		printf("Ener no. of pertitions:(press 0 to terminame.)\n");
		scanf("%d",&m);
		if(m==0)
			break;
		printf("Enter size of each partitions\n:");
		for(i=1;i<=m;i++)
		{
			scanf("%d",&par[i]);
			temp[i]=par[i];
		}
		printf("Enter no.of processes:\n");
		scanf("%d",&n);
		printf("Enter size of each process:\n");
		for(i=1;i<=n;i++)
			scanf("%d",&p[i]);
		//first fit
		for(i=1;i<=n;i++)
			alct[i]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(par[j]>=p[i])
				{
					alct[i]=j;
					par[j]-=p[i];
					break;
				}
			}
		}
		printf("First fit:\n");
		for(i=1;i<=n;i++)
		{
			printf("Process %d ",i);
			if(alct[i])
				printf("is allocated in partition %d.\n",alct[i]);
			else
				printf("has to wait.\n");
		}
		//best fit
		for(i=1;i<=m;i++)
		{
			alct[i]=0;
			par[i]=temp[i];
		}
		for(;i<=n;i++)
			alct[i]=0;
		par[0]=9999;
		for(i=1;i<=n;i++)
		{
			best=0;
			for(j=1;j<=m;j++)
			{
				if(par[j]>=p[i] && par[j]<par[best])
					best=j;
			}
			if(best)
				alct[i]=best;
		}
		for(i=1;i<=n;i++)
		{
			printf("Process %d ",i);
			if(alct[i])
				printf("is allocated in partition %d\n",alct[i]);
			else
				printf("has to wait\n");
		}
		//worst fit
		for(i=1;i<=m;i++)
		{
			alct[i]=0;
			par[i]=temp[i];
		}
		for(;i<=n;i++)
			alct[i]=0;
		par[0]=-100;
		for(i=1;i<=n;i++)
		{
			worst=0;
			for(j=1;j<=m;j++)
			{
				if(par[j]>=p[i] && par[j]>par[worst])
					worst=j;
			}
			if(worst)
			{
				alct[i]=worst;
				par[worst]-=p[i];
			}
		}
		printf("worst fit\n");
		for(i=1;i<=n;i++)
		{
			printf("Process %d ",i);
			if(alct[i])
				printf("is allocated in partition %d\n",alct[i]);
			else
				printf("has to wait\n");
		}
	}
	return 0;
}





