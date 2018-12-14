#include<stdio.h>
#include<math.h>
long d[10000001];
int main()
{
	long n,t,i;
	double sum;
	d[0]=1;d[1]=1;
	sum=0;	
	for(i=2;i<10000001;i++)
	{
		sum+=log10(i);
		d[i]=floor(sum)+1;
	}
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		printf("%ld\n",d[n]);
	}
	return 0;
}