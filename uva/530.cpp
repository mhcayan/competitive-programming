#include<stdio.h>
long gcd(long a,long b);
void divbygcd(long *a,long *b);
long com(long n,long k);
int main()
{
	long n,k;
	while(scanf("%ld %ld",&n,&k))
	{
		if(!n && !k)
			break;
		printf("%ld\n",com(n,k));
	}
	return 0;
}
long com(long n,long k)
{
	long tomul,todiv,denum=1,num=1,i;
	if(k>n/2)
		k=n-k;
	for(i=k;i;i--)
	{
		tomul=n--;
		todiv=i;
		divbygcd(&tomul,&todiv);
		divbygcd(&tomul,&denum);
		divbygcd(&num,&todiv);
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


