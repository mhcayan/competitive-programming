#include<stdio.h>
#include<math.h>
#define N 20000000
int sieve();
long a[20000010],flag[20000010],t[20000010];
int main()
{
	long s;
	sieve();
	while(scanf("%ld",&s)==1)
	{
		printf("(%ld, %ld)\n",a[t[s]],a[t[s]+1]);
	}
	return 0;
}
int sieve()
{
	long i,j,c,k,m;
	for(i=4;i<=N;i+=2)
		flag[i]=1;
	m=sqrt(N);
	c=-1;
	k=0;
	a[++c]=2;
	for(i=3;i<=N;i+=2)
	{
		if(flag[i]==0)
		{
			a[++c]=i;
			if(a[c]-a[c-1]==2)
				t[++k]=c-1;
			if(i<=m)
			{
				for(j=i*i;j<=N;j+=2*i)
					flag[j]=1;
			}
		}
	}
	return 0;
}
