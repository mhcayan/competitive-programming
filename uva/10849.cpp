#include<stdio.h>
int main()
{
	long c,n,i,j,k,l,t;
	scanf("%ld",&c);
	while(c--)
	{
		scanf("%ld",&t);
		scanf("%ld",&n);
		while(t--)
		{
			scanf("%ld %ld %ld %ld",&i,&j,&k,&l);
            if(i==k && j==l)
				printf("0\n");
			else if((i+j+k+l)%2)
			{
				printf("no move\n");
			}
			else if((i+j)==(k+l)||(i-j)==(k-l))
			{
				printf("1\n");
			}
			else
				printf("2\n");
		}
	}
	return 0;
}
