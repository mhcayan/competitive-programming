#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define MAX 5000000
unsigned long long e[5000003];
bool flag[5000003];
void sieve()
{
	long i,j;
	for(i=2;i<=MAX;i++)
		e[i]=i;
	for(i=2;i<=MAX;i++)
	{
		if(flag[i]==0)
		{
			for(j=i;j<=MAX;j+=i)
			{
				flag[j]=1;
				e[j]*=(i-1);
				ej]/=i;
			}
		}
	}
	for(i=2;i<=MAX;i++)
		e[i]=e[i-1]+e[i]*e[i];
}
int main()
{
	sieve();
	long cas,t,a,b;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld %ld",&a,&b);
		printf("Case %ld: %llu\n",t,e[b]-e[a-1]);
	}
	return 0;
}