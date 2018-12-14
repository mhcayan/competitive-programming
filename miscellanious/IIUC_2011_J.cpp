#include<stdio.h>
int main()
{
	int n,a[1000],i,d[1000][1000],u[21],f,flag,sumr,sumc,m,sum,j,v;
	char b[1000],c[1000];
	while(scanf("%d",&n)==1)
	{
    	m=n*n;
		for(i=0;i<m;i++)
		{
			scanf("%d",&a[i]);
			d[i/n][i%n]=a[i];
		}
		getchar();
		gets(b);
		flag=1;
		for(i=0;i<21;i++)
			u[i]=0;
		for(i=0;i<m;i++)
		{
			u[a[i]]++;
			if(u[a[i]]>1)
				flag=0;
		}
		if(flag==0)
		{
			printf("NOT A MAGIC SQUIRE\n");
			continue;
		}
		f=0;
		for(i=0;i<n;i++)
		{
			sum=0;
			for(j=0;j<n;j++)
			{
				sum+=d[i][j];
				if(f)
				{
					if(sum!=v)
					{
						printf("NOT A MAGIC SQUIRE\n");
						flag=0;
					}
				}
				f=1;
				v=sum;
			}
		}
		if(flag==0)
			continue;
		f=0;
	    for(i=0;i<n;i++)
		{
			sum=0;
			for(j=0;j<n;j++)
			{
				sum+=d[j][i];
				if(f)
				{
					if(sum=!v)
					{
						printf("NOT A MAGIC SQUIRE\n");
						flag=0;
					}
				}
				f=1;
				v=sum;
			}
		}
		if(flag==0)
			continue;
		sumr=sumc=0;
		for(i=0;i<n;i++)
		{
			sumr+=d[i][i];
			sumc+=d[i][n-1-i];
		}
		if(sumr!=v || sumc!=v)
		{
			printf("NOT A MAGIC SQUIRE\n");
			continue;
		}
		for(i=0;i<m;i++)
		{
			c[a[i]-1]=b[i];
		}
		c[i]='\0';
		printf("%s\n",c);
	}
	return 0;
}