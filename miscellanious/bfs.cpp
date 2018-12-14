#include<stdio.h>
int main()
{
	int a[100][100],i,j,n,queue[100],origin[100],status[100],m,flag,front,rear,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		status[i]=1;
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("enter starting and end node\n");
	scanf("%d %d",&m,&n);
	flag=front=rear=0;
	queue[front]=m;
	origin[0]=-1;
	c=1;
	while(rear>=front)
	{
		for(i=1;i<=n;i++)
		{
			if(a[m][i]==1)
			{
				if(status[i]==1)
				{
					rear++;
					queue[rear]=i;
                    status[i]=2;
					origin[c]=m;
					if(i==n)
					{
						flag=1;
						break;
					}	
					c++;
				}
			}
		}
		if(flag)
			break;
		m=queue[front];
		front++;
		status[m]=3;
	}
	for(i=0;i<=rear;i++)
	{
		printf("%d",queue[i]);
	}
	printf("\n");
	return 0;
}

		
