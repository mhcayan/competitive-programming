#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
long long countz(double n)
{
	long long count=0;
	while(n>0)
	{
		n=n/5;
		count+=n;
	}
	return count;
}
int main()
{
	double n;
	while(scanf("%lf",&n))
	printf("%lld\n",countz(n));
	return 0;
}
