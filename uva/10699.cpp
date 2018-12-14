#include<stdio.h>
#include<math.h>
int sieve();
bool status[1000009];
int main()
{
	long n,m,i,count;
	sieve();
	while(scanf("%ld",&n))
	{
		if(n==0)
			break;
		m=sqrt(n);
		count=0;
		if(status[n]==0)
			count++;
		for(i=2;i<=m;i++)
		{
			if(n%i==0)
			{
				if(status[i]==0)
					count++;
				if(status[n/i]==0)
					count++;
			}
		}
		if(status[m]==0 && m*m==n)
			count--;
		printf("%ld : %ld\n",n,count);
	}
	return 0;
}
int sieve()
{
	long i,j;
	for(i=4;i<=1000000;i+=2)
		status[i]=1;
	for(i=3;i<1000000;i+=2)
	{
		if(status[i]==0)
		{
			if(i<1000)
			{
				for(j=i*i;j<1000000;j+=2*i)
					status[j]=1;
			}
		}
	}
	return 0;
}
