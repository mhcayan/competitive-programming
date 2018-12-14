#include<stdio.h>
#include<string.h>
long dp[10013][1003];
char a[5000];
inline long min(long x,long y,long z)
{
	if(x<y)
		return x<z?x:z;
	else
		return y<z?y:z;
}
long find(long i,long j)
{
	if(i>j)
		return 0;
	if(dp[i][j]>-1)
		return dp[i][j];
	if(a[i]==a[j])
		return dp[i][j]=find(i+1,j-1);
	else
	{
		long x,y,z;
		x=1+find(i+1,j);
		y=1+find(i,j-1);
		z=1+find(i+1,j-1);
		return dp[i][j]=min(x,y,z);
	}
}

int main()
{
	long cas,t,i,j,l;
	scanf("%ld",&cas);
	getchar();
	for(t=1;t<=cas;t++)
	{
		gets(a);
		l=strlen(a);
		for(i=0;i<l;i++)
		{
			for(j=i;j<l;j++)
				dp[i][j]=-1;
		}
		printf("Case %ld: %ld\n",t,find(0,l-1));
	}
	return 0;
}
