#include<cstdio>
#include<algorithm>
bool flag[100000000];
long p[10000000];
using namespace std;
int sieve()
{
	p[0]=2;
	c=1;
	for(i=3;i<=3162;i++)
	{
		if(flag[i]==0)
			p[c++]=i;
		for(j=i*i;j<=9999999;j+=i+i)
			flag[j]=1;
	}
	return 0;
}
int main()
{
	long long n,i;
	while(scanf("%lld",&n) && n)
	{
		i=0;
		if(n==0)
			printf("%ld\n",n);
		else
		{
		while(n)
		{
			s[i++]=n%3+'0';
			n=n/3;
		}
		s[i]='\0';
		reverse(s,s+i);
		printf("%s\n",s);
		}
	}
	return 0;
}