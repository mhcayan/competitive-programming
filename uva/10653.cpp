#include<stdio.h>
bool vis[1000][1000];
long dis[1000][1000];
int main()
{
	long r,c,i,x[4]={0,-1,0,1},y[4]={-1,0,1,0},j;
	long row,n1,n2,m1,m2,q1[15000],q2[15000],s1,s2,d1,d2,rn,cn,b,front,rear;
	while(scanf("%ld %ld",&r,&c))
	{
		if(r==0)
			break;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
				vis[i][j]=0;
		}
		scanf("%ld",&row);
		while(row--)
		{
			scanf("%ld %ld",&rn,&b);
			while(b--)
			{
				scanf("%ld",&cn);
				vis[rn][cn]=1;
			}
		}
		scanf("%ld %ld %ld %ld",&s1,&s2,&d1,&d2);
		front=rear=1;
		q1[front]=s1;
		q2[front]=s2;
		vis[s1][s2]=1;
		dis[s1][s2]=0;
		while(front<=rear)
		{
			n1=q1[front];
			n2=q2[front++];
			for(i=0;i<4;i++)
			{
				m1=n1+x[i];
				m2=n2+y[i];
				if(m1>-1 && m2>-1 && m1<r && m2<c)
				{
					if(vis[m1][m2]==0)
					{
					    dis[m1][m2]=1+dis[n1][n2]; 
					    if(m1==d1 && m2==d2)
						{
						    front=rear+1;
						    break;
						}
					    q1[++rear]=m1;
					    q2[rear]=m2;
					    vis[m1][m2]=1;
					}
				}
			}
		}
		printf("%ld\n",dis[d1][d2]);
	}
	return 0;
}



