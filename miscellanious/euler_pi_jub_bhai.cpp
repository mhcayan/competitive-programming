#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define MAX 50
#define i64 unsigned long long
#define nextint(ret) ret=0;while(*ptr<48)ptr++;do{ret=ret*10+*ptr++-48;}while(*ptr>47);
 
int e[MAX + 1];
i64 sum[MAX + 1];
 
static char buff[1600000], *ptr = buff;
void sieve()
{
	register int i;
	for(i=2;i<=MAX;i+=2)
	{
		e[i]=i>>1;
		printf("%d  %d\n",i,e[i]);
	}
}
int main()
{
	sieve();
	return 0;
}