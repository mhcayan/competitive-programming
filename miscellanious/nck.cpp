#include<stdio.h>
long gcd(long a,long b)
{
	long r;
	while(1)
    {
        r=b%a;
        if(r==0)
            break;
        b=a;
        a=r;
    }
	return a;
}
void divbygcd(long &x,long &y)
{
	long g=gcd(x,y);
	x/=g;
	y/=g;
}
long nck(long n,long k)
{
	long num=1,den=1,tomul=1,todiv=1,i;
	if(k>n-k)
		k=n-k;
	for(i=k;i;i--)
	{
		tomul=n-k+i;
		todiv=i;
		divbygcd(tomul,todiv);
		divbygcd(tomul,den);
		divbygcd(num,todiv);
		num*=tomul;
		den*=todiv;
	}
	return num/den;
}


int main()
{
	long n,k;
	while(scanf("%ld %ld",&n,&k)==2)
	{
		printf("%ld\n",nck(n,k));
	}
	return 0;
}