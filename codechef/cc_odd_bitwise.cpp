#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	long t,n,i,m;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		m=n;
		for(i=1;n>>i;i++)
		{
			m=m|n>>i;
		}
		m+=1;
		printf("%ld\n",m>>1);
	}
	return 0;
}
