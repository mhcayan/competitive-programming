#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
long pr[100000];
bool flag[1000009];
void sieve()
{
	long i,j,c=0;
	pr[c++]=2;
	for(i=3;i<=1000;i+=2)
	{
		if(flag[i]==0)
		{
			pr[c++]=i;
			for(j=i*i;j<=1000020;j+=i+i)
				flag[j]=1;
		}
	}
	for(;i<=1000020;i+=2)
	{
		if(flag[i]==0)
			pr[c++]=i;
	}
}
int main()
{
	long t,cas,n,c,res,m,i;
	sieve();
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld",&n);
		m=sqrt(n);
		res=1;
		for(i=0;pr[i]<=m;i++)
		{
			if(n%pr[i]==0)
			{
				c=1;
				while(n%pr[i]==0)
				{
					n/=pr[i];
					c++;
				}
				m=sqrt(n);
				res*=c;
			}
		}
		if(n>1)
			res*=2;
		printf("Case %ld: %ld\n",t,res-1);
	}
	return 0;
}