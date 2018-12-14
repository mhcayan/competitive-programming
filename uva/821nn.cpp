#include<stdio.h>
int main()
{
	long a,b,path[101][101],t,tp,i,j,k,vis[101],loc[1000],c=1,d,sum;
	while(scanf("%ld %ld",&a,&b))
	{
		if(a==0)
			break;
		for(i=1;i<=100;i++)
		{
			vis[i]=0;
			for(j=1;j<=100;j++)
				path[i][j]=99999;
		}
		path[1][2]=1;
		t=2;
		vis[a]=1;
		vis[b]=1;
		loc[a]=1;
		loc[b]=2;
		while(scanf("%ld %ld",&a,&b))
		{
			if(a==0)
				break;
			if(vis[a]==0)
			{
				vis[a]=1;
				t++;
				loc[a]=t;
			}
			if(vis[b]==0)
			{
				vis[b]=1;
				t++;
				loc[b]=t;
			}
			path[loc[a]][loc[b]]=1;
		}
		for(k=1;k<=t;k++)
		{
			for(i=1;i<=t;i++)
			{
				for(j=1;j<=t;j++)
				{
					sum=path[i][k]+path[k][j];
					if(path[i][j]>sum)
						path[i][j]=sum;
				}
			}
		}
		sum=0;
		tp=1;
		for(d=t-2+1;d<=t;d++)
			tp*=d;
        printf("%ld\n",tp);
		for(i=1;i<=t;i++)
		{
			for(j=1;j<=t;j++)
			{
				if(path[i][j]<99999)
					sum+=path[i][j];
			}
		}
		printf("%ld\n",sum);
		printf("Case %ld: average length between pages = %.3lf clicks\n",c++,(double)sum/tp);
	}
	return 0;
}
				
