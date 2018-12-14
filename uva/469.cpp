#include<stdio.h>
int bfs(int p,int q);
int r,c,x[8]={-1,-1,-1,0,0,1,1,1},y[8]={-1,0,1,-1,1,-1,0,1};
char a[101][101];
int main()
{
	int t,i,p,q;
	char s[1000];
	scanf("%d",&t);
	getchar();
	getchar();
	while(t--)
	{
		r=0;
		while(gets(s))
		{
			if(s[0]=='W'||s[0]=='L')
			{
				r++;
				for(i=0;s[i];i++)
				{
					a[r][i+1]=s[i];
				}
			}
			else
				break;
		}
		c=i;
		if(s[0]>='0'||s[0]<='9')
			sscanf(s,"%d %d",&p,&q);
		printf("%d\n",bfs(p,q));
		while(gets(s))
		{
			if(s[0]=='\0')
				break;
			sscanf(s,"%d %d",&p,&q);
			printf("%d\n",bfs(p,q));
		}
		if(t)
			printf("\n");
	}
	return 0;
}
int bfs(int p,int q)
{
	int front,rear,i,q1[10001],q2[10001],m,n,vis[101][101]={0};
	front=rear=1;
	vis[p][q]=1;
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
				if(a[m][n]=='W' && vis[m][n]==0)
				{
					vis[m][n]=1;
					q1[++rear]=m;
					q2[rear]=n;
				}
			}
		}
	}
	return rear;
}

					
