//pregenerating the prime factor f of n where 1<f<n
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define MAX 1001
int deg[1001],f[1001][4];
void sieve()
{
	int i,j;
	for(i=4;i<=MAX;i+=2)
		f[i][deg[i]++]=2;
	for(i=3;i<=MAX;i+=2)
	{
		if(deg[i]==0)
		{
			for(j=i+i;j<=MAX;j+=i)
				f[j][deg[j]++]=i;
		}
	}
}
int main()
{
	int i,n;
	sieve();
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<deg[n];i++)
			printf("%d ",f[n][i]);
		printf("\n");
	}
	return 0;
}
