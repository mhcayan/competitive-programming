#include<stdio.h>
#include<string.h>
int main()
{
	char ch,flag;
	int t,i,j,k,m,n,front,rear,q1[20000],q2[20000],vis[150][150],dis[150][150],a,b,c,d,di,dj,si,sj;
	int x[8]={-2,-2,-1,-1,1,1,2,2},y[8]={-1,1,-2,2,-2,2,-1,1},k1[8]={-1,-1,-1,0,0,1,1,1},k2[8]={-1,0,1,-1,1,-1,0,1};
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		getchar();
		memset(vis,0,sizeof(vis));
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				ch=getchar();
				if(ch=='Z')
				{
					vis[i][j]=1;
                    for(k=0;k<8;k++)
					{
					    a=i+x[k];
					    b=j+y[k];
					    if(a>0 && b>0 && a<=m && b<=n)
						{
							vis[a][b]=1;
						}
					}
				}
				else if(ch=='A')
				{
					si=i;
					sj=j;
				}
				else if(ch=='B')
				{
					di=i;
					dj=j;
				}
			}
			getchar();
		}
		vis[di][dj]=0;
		front=rear=1;
		q1[front]=si;
		q2[front]=sj;
		vis[si][sj]=1;
		dis[si][sj]=0;
		flag=0;
		while(front<=rear)
		{
			a=q1[front];
			b=q2[front];
			front++;
			for(i=0;i<8;i++)
			{
				c=a+k1[i];
				d=b+k2[i];
				if(c>0 && d>0 && c<=m && d<=n && vis[c][d]==0)
				{
					vis[c][d]=1;
					rear++;
					q1[rear]=c;
					q2[rear]=d;
					dis[c][d]=1+dis[a][b];
					if(c==di && d==dj)
					{
						flag=1;
						break;
					}
				}
			}
			if(flag)
				break;
		}
		if(flag)
			printf("Minimal possible length of a trip is %d\n",dis[di][dj]);
		else
		    printf("King Peter, you can't go now!\n");
	}
	return 0;
}





