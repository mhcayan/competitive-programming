#include<stdio.h>
#include<string.h>
int main()
{
	long x[4]={-1,0,1,0},y[4]={0,1,0,-1},vis[100][100],dis[100][100],c,d,a,b,s1,s2,d1,d2,i,f,n,r,r1,r2,front,rear;
	long q1[1000],q2[1000];
	while(scanf("%ld",&n)==1)
	{
		printf("Enter source :\n");
		scanf("%ld %ld",&s1,&s2);
		printf("Enter destination\n");
		scanf("%ld %ld",&d1,&d2);
		printf("how many restricted block:\n");
		scanf("%ld",&r);
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		for(i=0;i<r;i++)
		{
			scanf("%ld %ld",&r1,&r2);
			vis[r1][r2]=1;
		}
		front=rear=1;
		q1[front]=s1;
		q2[front]=s2;
		vis[s1][s2]=1;
		f=0;
		while(front<=rear)
		{
			a=q1[front];
			b=q2[front];
		//	printf("%ld %ld\n",a,b);
			front++;
			for(i=0;i<4;i++)
			{
				c=a+x[i];
				d=b+y[i];
				//printf("%ld %ld\n",c,d);
				if(c>0 && d>0 && c<=n && d<=n && vis[c][d]==0)
				{
					q1[++rear]=c;
					q2[rear]=d;
					vis[c][d]=1;
					dis[c][d]=1+dis[a][b];
					if(c==d1 && d==d2)
					{
						f=1;
						break;
					}
				}
			}
			if(f)
				break;
		}
		if(f)
			printf("distance=%ld\n",dis[d1][d2]);
		else
			printf("not possible\n");
	}
	return 0;
}



