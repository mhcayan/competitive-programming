#include<stdio.h>
#define max(a,b) (a>b)?a:b
long ks(long i,long c);
long w[1000],v[1000],n;
int main()
{
	long C,i;
	scanf("%ld",&C);
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
		scanf("%ld",&v[i]);
	for(i=1;i<=n;i++)
		scanf("%ld",&w[i]);
	printf("profit=%ld\n",ks(1,C));
	return 0;
}
long ks(long i,long c)
{
	if(i>n)
		return 0;
	if(w[i]>c)
		return ks(i+1,c);
	else
	{
		return(max(ks(i+1,c),v[i]+ks(i+1,c-w[i])));
	}
}

