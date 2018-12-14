#include<stdio.h>
long p[2000000],c,flag[3000000],count[3000000];
int sieve()
{
	long i,j;
	c=0;
	p[c++]=2;
	for(i=3;i<=2703663;i+=2)
	{
		if(flag[i]==0)
			p[c++]=i;
		if(i<1645)
		{
			for(j=i*i;j<1001;j+=2*i)
				flag[j]=1;
		}
	}
	return 0;
}
int fact()
{
	long sum,i,j,n;
	sum=0;
	count[0]=1;
	count[1]=1;
	for(i=2;i<=2702663;i++)
	{
		n=i;
		j=0;
		while(n!=1)
		{
			if(n%p[j]==0)
			{
				sum++;
				n=n/p[j];
			}
			else
				j++;
		}
		count[i]=sum;
		//printf("%ld\n",count[i]);
	}
	printf("%ld\n",count[1000]);
	return  0;
}
int main()
{
	long i,t,n;
	scanf("%ld",&t);
	sieve();
	fact();
	while(t--)
	{
		scanf("%ld",&n);
		for(i=0;count[i]<=n;i++);
		printf("%ld\n",i);
	}
	return 0;
}