#include<stdio.h>
#include<math.h>
int isprime(long n)
{
	long m,i;
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else if(n%2==0)
		return 0;
	else
	{
		m=sqrt(n);
		for(i=3;i<=m;i+=2)
		{
			if(n%i==0)
				return 0;
		}
		return 1;
	}

}
int main()
{
    long n;
    while(scanf("%ld",&n))
    {
        if(isprime(n))                  
            printf("yes\n");
        else
            printf("no\n");
    }                  
    return 0;
}
