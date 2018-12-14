#include<cstdio>
using namespace std;
int main()
{
	long long n, cur;
	while(scanf("%lld", &n) == 1)
	{
		cur = 2;
		for(long long i = 1; i <= n; i++)
		{
			printf("%lld\n", (i + 1) * (i + 1) - cur);
			cur = i + 1;
		}
	}
	return 0;
}
