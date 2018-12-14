#include<stdio.h>
#include<string.h>
int main()
{
	int a[200][200],i,j,x[8]={-1,-1,-1,0,0,1,1,1},y[8]={-1,0,1,-1,1,-1,0,1},deposit,m,n,k,front,rear,q1[10000],q2[10000],p,q,r,s;
    char ch;
	while(scanf("%d %d",&m,&n))
	{
		getchar();
		if(m==0)
			break;
		memset(a,0,sizeof(a));
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%c",&ch);
				if(ch=='*')
					a[i][j]=0;
				else
					a[i][j]=1;
			}
			getchar();
		}
		deposit=0;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]==1)
				{
					deposit++;
					front=rear=1;
					q1[front]=i;
					q2[front]=j;
					a[i][j]=0;
					while(front<=rear)
					{
						p=q1[front];
						q=q2[front];
						front++;
						for(k=0;k<8;k++)
						{
							r=p+x[k];
							s=q+y[k];
							if(a[r][s]==1)
							{
								rear++;
								q1[rear]=r;
								q2[rear]=s;
								a[r][s]=0;
							}
						}
					}
				}
			}
		}
		printf("%d\n",deposit);
	}
	return 0;
}

