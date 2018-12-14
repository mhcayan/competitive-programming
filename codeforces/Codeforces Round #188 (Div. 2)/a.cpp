#include<stdio.h>
int main()
{
	long long n,k;
	while(scanf("%I64d %I64d",&n,&k)==2)
	{
		if(n%2==0)
		{
			if(k<=n/2)
			{
			
			    printf("%I64d\n",2*(k-1)+1);
			    
			}
			else
			{
				k=k-n/2;
				printf("%I64d\n",2*k);
			}
		}
		else
		{
			if(k<=n/2+1)
			    printf("%I64d\n",2*(k-1)+1);
			else
			{
				k=k-n/2-1;
				printf("%I64d\n",2*k);
			}
			
		}
	}
}
