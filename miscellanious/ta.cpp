#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<queue>
using namespace std;
bool flag[10000002];
long pr[10000002];
inline long square(int x)
{
	return x*x;
}
void sieve(long n)
{
	long i,j,c=0,m;
	pr[c++]=2;
	m=sqrt(n);
	for(i=3;i<=m;i+=2)
	{
		if(flag[i]==0)
		{
			pr[c++]=i;
			for(j=i*i;j<=n;j+=i+i)
				flag[j]=1;
		}
	}
	for(;i<=n;i+=2)
	{
		if(flag[i]==0)
			pr[c++]=i;
	}
}
long power(long n,long m,long b)
{
	if(m==0)
		return 1;
	else if(m%2==0)
		return square(power(n,m/2,b))%b;
	else
		return ((n%b)*power(n,m-1,b))%b;
}
int main()
{
	long n,m,res,i,p,q;
	sieve(4000);
	while(scanf("%ld %ld",&p,&q))
	{
		if(p==0 && q==0)
			break;
		n=p;
		m=sqrt(n);
		res=n;
		for(i=0;pr[i]<=m;i++)
		{
			if(n%pr[i]==0)
			{
				res/=pr[i];
				res*=(pr[i]-1);
				while(n%pr[i]==0)
					n=n/pr[i];
				m=sqrt(n);
			}
		}
		if(n>1)
		{
			res*=(n-1);
			res/=n;
		}
		//printf("%ld\n",res);
		printf("%ld\n",power(2,100000000,201004));
		res=(power(p,q-1,201004)*(res%201004))%201004;
		printf("%ld\n",res);
	}
	return 0;
}