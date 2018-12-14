#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
long count5(double n)
{
	long count=0;
	while(n>0)
	{
		count+=n/5;
		n/=5;
	}
	return count;
}
long count2(double n)
{
	long count=0;
	while(n>0)
	{
		count+=n/2;
		n=n/2;
	}
	return count;
}
int main()
{
	long cas,t,n,p,q,r,m,count,c2,c5;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld %ld %ld %ld",&n,&r,&p,&q);
		m=p;
		count=0;
		while(m%5==0)
		{
			count++;
			m/=5;
		}
		c5=count5(n)-count5(r)-count5(n-r)+count*q;
		m=p;
		count=0;
		while(m%2==0)
		{
			m=m/2;
			count++;
		}
		c2=count2(n)-count2(r)-count2(n-r)+count*q;
		printf("Case %ld: %ld\n",t,c5<c2?c5:c2);
	}
	return 0;
}

