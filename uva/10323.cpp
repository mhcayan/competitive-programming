#include<stdio.h>
int main()
{
	long long fact[20],n;
	fact[8]=40320;
	fact[9]=362880;
	fact[10]=3628800;
	fact[11]=39916800;
	fact[12]=479001600;
	fact[13]=6227020800LL;
	while(scanf("%llu",&n)==1)
	{
        if(n<0)
        {
            n=-n;
            if(n%2)
                printf("Overflow!\n");
            else
                printf("Underflow!\n");
        }
		else if(n<8)
			printf("Underflow!\n");
		else if(n>13)
			printf("Overflow!\n");
		else
			printf("%llu\n",fact[n]);
	}
	return 0;
}
