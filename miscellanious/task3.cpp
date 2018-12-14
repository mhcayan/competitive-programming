#include<stdio.h>
#include<string.h>
long par[10000];
int path(int n);
int main()
{
	long c,t,i,ar[10000],front,rear,s,a,b,n,dis[100],vis[10000],queue[10000];
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		memset(vis,0,sizeof(vis));
		scanf("%ld",&s);
		for(i=0;i<s;i++)
			scanf("%ld",&ar[i]);
		scanf("%ld %ld",&a,&b);
	    front=rear=1;
	    queue[front]=a;
		dis[a]=0;
		vis[a]=1;
	    par[a]=-1;
	    int flag=0;
	    while(front<=rear)
		{
			n=queue[front++];
		    for(i=0;i<s;i++)
			{
				if(n+ar[i]<=b && vis[n+ar[i]]==0)
				{
					queue[++rear]=n+ar[i];
					par[n+ar[i]]=n;
					dis[n+ar[i]]=1+dis[n];
					vis[n+ar[i]]=1;
                    if(queue[rear]==b)
					{
						flag=1;
				        break;
					}
				}
			}
		    if(flag)
				break;
		}
		printf("Case %ld:\n",t);
	    if(flag)
		{
			printf("%ld\n",dis[queue[rear]]);
			path(b);
			printf("=%ld\n",b);
		}
	    else
		    printf("-1\n");
	}
	return 0;
}
int path(int n)
{
	if(par[n]==-1)
		printf("%ld",n);
	else
	{
		path(par[n]);
		printf("+%ld",n-par[n]);
	}
	return 0;
}

	
