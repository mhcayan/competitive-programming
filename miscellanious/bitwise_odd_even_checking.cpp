#include<stdio.h>
int main()
{
	long a;
	while(scanf("%ld",&a)==1)
	{
		if(a&1)
			printf("%ld is odd\n",a);
		else
			printf("%ld is even\n",a);
	}
	return 0;
}