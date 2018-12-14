#include<stdio.h>
long flag[11000],a[11000],c;
int sieve();
int main()
{
	long n,x,i,t,min,p,v;
	scanf("%ld",&t);
	sieve();
	while(t--)
	{
		scanf("%ld",&n);
		min=n;
		for(i=0;a[i]<=n;i++)
		{
			p=n/a[i];
			v=p*a[i];
			if(v<min)
			{
				min=v;
				x=a[i];
			}
		}
		printf("%ld\n",x);
	}
	return 0;
}
int sieve()
{
	long i,j;
	for(i=4;i<=10007;i+=2)
		flag[i]=1;
	a[c++]=2;
	for(i=3;i<=10007;i+=2)
	{
		if(flag[i]==0)
		{
			a[c++]=i;
			for(j=i*i;j<=10007;j+=2*i)
				flag[j]=1;
		}
	}
	return 0;
}



