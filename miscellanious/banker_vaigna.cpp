#include<stdio.h>

int main()
{
	int vis[100],n,i,seq[100],size,al[100][100],max[100][100],need[100][100],work[100],j,m;
	while(1)
	{
		size=0;
		printf("Enter number of processes and instances:(enter \"0 0\" to terminate)\n");
	    scanf("%d %d",&n,&m);
	    printf("Enter allocation:\n");
	    for(i=0;i<n;i++)
		{
			vis[i]=0;
			for(j=0;j<m;j++)
		        scanf("%d",&al[i][j]);
		}
	    printf("Enter maximum number of instances for each process\n");
	    for(i=0;i<n;i++)
			for(j=0;j<m;j++)
		        scanf("%d",&max[i][j]);
	    printf("Enter no of available instances:\n");
	    for(i=0;i<m;i++)
	        scanf("%d",&work[i]);
        for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
		        need[i][j]=max[i][j]-al[i][j];
		}
	    while(1)
		{
		    for(i=0;i<n;i++)
			{
				if(vis[i]==0)
				{
					for(j=0;j<m;j++)
					{
						if(need[i][j]>work[j])
				           break;
					}
					if(j==m)
					{
						vis[i]=1;
						seq[size++]=i;
						for(j=0;j<m;j++)
							work[j]+=al[i][j];
						break;
					}
				}
			}
			if(size==n || i==n)
			    break;
		}
		if(size==n)
		{
			printf("Safe sequence is:\n");
		    for(i=0;i<n;i++)
			    printf("%d\n",seq[i]);
		}
	    else
		    printf("No safe sequence is possible.\n");
	}
	return 0;
}


