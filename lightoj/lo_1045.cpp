#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define pi 2*acos(double(0.0))
#define e exp(1)
double a[1000003],c[1000003];
int main()
{
	long t,cas,n,b;
	scanf("%ld",&cas);
	for(t=1;t<=1000000;t++)
	{
		c[t]=log(t);
		a[t]=a[t-1]+c[t];
	}
	for(t=1;t<=cas;t++)
	{
		scanf("%ld %ld",&n,&b);
		//int ans =floor((log(2*pi*n)/2+n*log(n/e))/log(b))+1;//formula
		printf("Case %ld: %.0lf %d\n",t,floor(a[n]/c[b])+1);
	}
	return 0;
}