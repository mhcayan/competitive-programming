#include<stdio.h>
long E,memo[110][210];
struct{
	int a[550],size;
}node[150];
int dp(long cur,long trip)
{
	long i,c;
	if(memo[cur][trip]!=2)
	    return memo[cur][trip];
	else if(trip==1)
	{
		for(i=0;i<node[cur].size;i++)
		{
			if(node[cur].a[i]==E)
				return 1;
		}
		return memo[cur][1]=0;
	}
	else
	{
		for(i=0;i<node[cur].size;i++)
		{
           c=dp(node[cur].a[i],trip-1);
           if(c)
			   return c;
		   else
			   memo[cur][trip]=c;
		}
		return memo[cur][trip];
	}
}
int main()
{
	long C,L,S,p,q,D,i,j;
	while(scanf("%ld %ld",&C,&L) && C)
	{
		for(i=1;i<=C;i++)
			node[i].size=0;
		for(i=0;i<L;i++)
		{
			scanf("%ld %ld",&p,&q);
			node[p].a[node[p].size++]=q;
			node[q].a[node[q].size++]=p;
		}
	
		scanf("%ld %ld %ld",&S,&E,&D);
	
		if(D==0)
		{
               // printf("yes");	
			if(S==E)
		        printf("Yes, Teobaldo can travel.\n");
	        else
		        printf("No, Teobaldo can not travel.\n");

		}
		else
		{
       	    for(i=1;i<=C;i++)
		    {
                for(j=1;j<=D;j++)
                    memo[i][j]=2;
            }
		    if(dp(S,D)==1)
		        printf("Yes, Teobaldo can travel.\n");
	        else
		        printf("No, Teobaldo can not travel.\n");
		}
	}
	return 0;
}

