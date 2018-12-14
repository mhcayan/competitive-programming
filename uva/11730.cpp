#include<stdio.h>
#include<string.h>
int sieve();
int a[10000];
int main()
{
	int s,t,c=1,front,rear,queue[10000],dis[10000],vis[1500],f,sum,n,i;
	sieve();
	while(scanf("%d %d",&s,&t))
	{
		if(s==0 && t==0)
			break;
		memset(vis,0,sizeof(vis));
		front=rear=1;
		queue[front]=s;
		dis[s]=0;
		f=0;
		if(s==t)
			printf("Case %d: 0\n",c);
		else
		{
			while(front<=rear)
			{
				n=queue[front++];
			    for(i=0;a[i]<n;i++)
				{
					if(n%a[i]==0)
					{
						sum=n+a[i];
				        if(sum<=t && vis[sum]==0)
						{
							queue[++rear]=sum;
					        vis[sum]=1;
					        dis[sum]=1+dis[n];
					        if(queue[rear]==t)
							{
								printf("Case %d: %d\n",c,dis[t]);
						        f=1;
						        break;
							}
						}
					}
				}
                if(f)
					break;
			}
		    if(f==0)
			    printf("Case %d: -1\n",c);
		}
		c++;
	}
	return 0;
}
int sieve()
{
	int flag[1000],i,j,c;
	for(i=3;i<1000;i+=2)
		flag[i]=0;
	a[0]=2;
	c=1;
	for(i=3;i<=1000;i+=2)
	{
		if(flag[i]==0)
		{
			a[c++]=i;
			if(i<32)
			{
				for(j=i*i;j<1000;j+=2*i)
					flag[j]=1;
			}
		}
	}
	a[c]=5000;
	return 0;
}


		