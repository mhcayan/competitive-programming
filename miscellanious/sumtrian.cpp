#include<stdio.h>
long a[110][110],memo[110][110],n;
int max(int a,int b)
{
	return a>b?a:b;
}
int func(long i,long j)
{
	if(i>n)
	{
           printf("l1 i=%ld j=%ld\n",i,j);
		return 0;
    }
	else if(memo[i][j])
	{
         printf("l2 i=%ld j=%ld\n",i,j);
		return memo[i][j];
    } 
	else
	{
        printf("l3 i=%ld j=%ld\n",i,j);
	    memo[i][j]=a[i][j]+max(func(i+1,j),func(i+1,j+1));
		return memo[i][j];
	}
}
int main()
{
	long t,i,j;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				scanf("%ld",&a[i][j]);
				memo[i][j]=0;
			}
		}
		printf("%ld\n",func(1,1));
	}
	return 0;
}
