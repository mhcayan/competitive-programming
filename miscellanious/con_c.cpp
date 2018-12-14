#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	long a[5],cas,t;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld %ld %ld",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		printf("Case %ld: %ld %ld %ld.\n",t,a[0],a[1],a[2]);
	}
	return 0;
}
