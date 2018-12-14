#include<stdio.h>
int main()
{
	long b,n,f,r;
	while(scanf("%ld",&n) && n)
	{
		f=1;
		r=n;
		b=r;
		while(f<r)
		{
			f++;
			b=f;
			f++;
			b++;
		}
		printf("%ld\n",b);
	}
	return 0;
}