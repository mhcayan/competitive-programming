#include<stdio.h>
#include<math.h>
long seive();
long a[10000000];
bool flag[100000001];
int main()
{
	long i,n,f;
	seive();
	while(scanf("%ld",&n)==1)
	{
		f=1;
		for(i=;a[i]<=n;i++)
		{
			if(flag[n-a[i]]==0)
			{
				printf("%ld is the sum of %ld and %ld.\n",n,a[i],n-a[i]);
				f=0;
				break;
			}
		}
		if(f)
			printf("%ld is not the sum of two primes!\n",n);
	}
	return 0;
}
long seive()
{
	long i,j,c=0;
	for(i=4;i<=100000000;i+=2)
		flag[i]=1;
	a[c++]=2;
	for(i=3;i<100000000;i+=2)
	{
		if(flag[i]==0)
		{
			a[c++]=i;
			if(i<10000)
			{
				for(j=i*i;j<100000000;j+=2*i)
					flag[j]=1;
			}
		}
	}
	return 0;
}
