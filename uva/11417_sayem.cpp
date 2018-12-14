#include<stdio.h>
long ar[1000][1000],save[1000];
long gcd(long a,long b);
int main()
{
	long n,i,j,g;
	save[0]=0;
	for(i=2;i<=500;i++)
	{
            g=0;
			for(j=1;j<i;j++)
					g+=gcd(j,i);
			save[i]=save[i-1]+g;
	}
	while(scanf("%ld",&n)&&n)
	{
		printf("%ld\n",save[n]);
	}
	return 0;
}
long gcd(long a,long b)
{
     long t;
    while(a%b)
	{
        t=b;
		b=a%b;
		a=t;
	}
	return b;
}
