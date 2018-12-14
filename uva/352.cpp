#include<stdio.h>
int dfs(int p,int q);
int x[8]={-1,-1,-1,0,0,1,1,1},y[8]={-1,0,1,-1,1,-1,0,1},a[100][100],n;
int main()
{
	char s[100];
	int i,j,c,t=0;
	while(scanf("%d",&n)==1)
	{
		getchar();
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			for(j=1;j<=n;j++)
			{
				if(s[j-1]=='1')
				    a[i][j]=1;
				else
					a[i][j]=0;
			}
		}
		c=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j])
				{
					c++;
					dfs(i,j);
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n",++t,c);
	}
	return 0;
}
int dfs(int p,int q)
{
	int c,d,front,rear,i,q1[1000],q2[1000];
	front=rear=1;
	q1[front]=p;
	q2[front]=q;
	while(front<=rear)
	{
		p=q1[front];
		q=q2[front++];
		for(i=0;i<8;i++)
		{
			c=p+x[i];
			d=q+y[i];
			if(c>0 && d>0 && c<=n && d<=n)
			{
				if(a[c][d])
				{
					a[c][d]=0;
					q1[++rear]=c;
					q2[rear]=d;
				}
			}
		}
	}
	return 0;
}


		
