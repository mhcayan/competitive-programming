#include<stdio.h>
int main()
{
	long c,g,l;
	scanf("%ld",&c);
	while(c--)
	{
		scanf("%ld %ld",&g,&l);
		if(l%g==0)
			printf("%ld %ld\n",g,l);
		else
			printf("-1\n");
	}
	return 0;
}