#include<stdio.h>
int main()
{
	long n,g;
	while(scanf("%ld",&n)&&n)
	{
		if(n>9)
		{
			while(n>9)
			{
			   g=0;
			   while(n!=0)
			   {
				   g+=n%10;
				   n=n/10;
			   }
			   n=g;
			}
		}
		 printf("%ld\n",n);
	}
    return 0;
}