#include<stdio.h>
int dfs(int p,int q);
int r,c,x[8]={-1,-1,-1,0,0,1,1,1},y[8]={-1,0,1,-1,1,-1,0,1};
char a[105][105];
int main()
{
	int i,j,count;
	char s[1000];
	while(scanf("%d %d",&r,&c))
	{
		if(!r&&!c)
			break;
		count=0;
		for(i=1;i<=r;i++)
		{
			scanf("%s",s);
			for(j=1;j<=c;j++)
			{
				a[i][j]=s[j-1];
			}
		}
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				if(a[i][j]=='*')
				{
				    if(dfs(i,j))
					    count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
int dfs(int p,int q)
{
	int flag=1,q1[10001],q2[10001],m,n,front,rear,i;
	a[p][q]='.';
	front=rear=1;
	q1[front]=p;
	q2[front]=q;
	while(front<=rear)
	{
		p=q1[front];
		q=q2[front++];
		for(i=0;i<8;i++)
		{
			m=p+x[i];
			n=q+y[i];
			if(m>0 && n>0 && m<=r && n<=c)
			{
				if(a[m][n]=='*')
				{
					a[m][n]='.';
					q1[++rear]=m;
					q2[rear]=n;
					flag=0;
				}
			}
		}
	}
	return flag;
}
			
