#include<stdio.h>
int main()
{
	long max,t=1,i,j,k,p,q,path[101][101],sum,tp,status[110],n,d;
	while(scanf("%ld %ld",&p,&q))
	{
		if(p==0)
			break;
		for(i=1;i<101;i++)
			for(j=1;j<101;j++)
				path[i][j]=99999;
		for(i=1;i<101;i++)
		{
			path[i][i]=0;
			status[i]=0;
		}
		max=0;
		path[p][q]=1;
		status[p]=1;
		status[q]=1;
		n=2;
		while(scanf("%ld %ld",&p,&q))
		{
			if(p==0)
				break;
			path[p][q]=1;
			if(p>max)
				max=p;
			if(q>max)
				max=q;
			if(status[p]==0)
			{
			    status[p]=1;
				n++;
			}
			if(status[q]==0)
			{
			    status[q]=1;
				n++;
			}
		}
		tp=1;
		d=n-2;
		for(;n>d;n--)
			tp*=n;
		for(k=1;k<=max;k++)
		{
			if(status[k])
			{
			    for(i=1;i<=max;i++)
				{
					if(status[i])
					{
				        for(j=1;j<=max;j++)
						{
							if(status[j])
							{
					            sum=path[i][k]+path[k][j];
					            if(sum<path[i][j])
						        path[i][j]=sum;
							}
						}
					}
				}
			}
		}
		sum=0;
		for(i=1;i<=max;i++)
		{
			if(status[i])
			{
			    for(j=1;j<=max;j++)
				{
					if(status[j])
					{
				        if(path[i][j]<99999)
					        sum+=path[i][j];
					}
				}
			}
		}
		printf("Case %ld: average length between pages = %.3lf clicks\n",t++,(double)sum/tp);
	}
	return 0;
}



		



