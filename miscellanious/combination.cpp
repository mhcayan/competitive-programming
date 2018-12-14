#include<stdio.h>
long gcd(long a,long b);
void divbygcd(long *a,long *b);
long com(long n,long k);
int main()
{
	long a,b;
	while(scanf("%ld %ld",&a,&b)==2)
		printf("%ld\n",com(a,b));
	return 0;
}
long gcd(long a,long b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
void divbygcd(long *a,long *b)
{
	long g=gcd(*a,*b);
	*a/=g;
	*b/=g;
}
long com(long n,long k)
{
	long num,denum,tomul,todiv,i;
	if(k>n/2)
		k=n-k;
	num=denum=1;
	for(i=k;i;i--)
	{
		todiv=i;
		tomul=n--;
		divbygcd(&tomul,&todiv);
		divbygcd(&num,&todiv);
		divbygcd(&tomul,&denum);
		num*=tomul;
		denum*=todiv;
	}
	return num/denum;
}