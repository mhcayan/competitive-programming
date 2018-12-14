#include<stdio.h>
long gcd(long a,long b);
void divbygcd(long *a,long *b);
long com(long n,long k);
int main()
{
	long n,m;
	while(scanf("%ld %ld",&n,&m))
	{
		if(n==0 && m==0)
			break;
		printf("%ld things taken %ld at a time is %ld exactly.\n",n,m,com(n,m));
	}
	return 0;
}
long com(long n,long k)
{
	long tomul,todiv,num=1,denum=1,i;
	if(k>n/2)
		k=n-k;
	for(i=k;i;i--)
	{
		tomul=n--;
		todiv=i;
		if(num>222222 || denum>222222)
		{
			divbygcd(&tomul,&todiv);
		    divbygcd(&tomul,&denum);
		    divbygcd(&todiv,&num);
		}
		num*=tomul;
		denum*=todiv;
	}
	return num/denum;
}
void divbygcd(long *a,long *b)
{
	long g=gcd(*a,*b);
	*a/=g;
	*b/=g;
}
long gcd(long a,long b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
