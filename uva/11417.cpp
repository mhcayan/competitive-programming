#include<stdio.h>
long ar[1000][1000];
long gcd(long a,long b);
int main()
{
	long n,i,j,g;
	while(scanf("%ld",&n))
	{
		if(n==0)
			break;
		g=0;
		for(i=n-1;i>1;i--)
		{
			for(j=i+1;j<=n;j++)
					g+=gcd(j,i);
		}
		printf("%ld\n",g+n-1);
	}
	return 0;
}
long gcd(long a,long b)
{
	if(ar[a][b])
		return ar[a][b];
    if(a%b==0)
		return b;
	else
	{
		int i=b;
		int j=a%b;
		return ar[i][j]=gcd(i,j);
	}
}
