#include<stdio.h>
int gcd(int a,int b)
{
	int r=a%b;
	if(r)
	    return gcd(b,r);
	return b;
}
int main()
{
	int cas,tc,a,b;
	scanf("%d",&cas);
	for(tc=1;tc<=cas;tc++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",gcd(a,b));
	}
	return 0;
}
