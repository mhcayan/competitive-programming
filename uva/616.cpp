#include<stdio.h>
#include<math.h>
int main()
{
	long n,j,k,m,flag;
	while(scanf("%ld",&n))
	{
		if(n<0)
			break;
		flag=0;
		for(k=ceil(sqrt(n));k>1;k--)
		{
			m=n;
			for(j=1;j<=k;j++)
			{
				m--;
				if(m<0 || m%k)
					break;
				else
					m=m-m/k;
			}
			if(j>k && m%k==0)
			{
				flag=1;
				break;
			}
		}
		if(flag)
			printf("%ld coconuts, %ld people and 1 monkey\n",n,k);
		else
			printf("%ld coconuts, no solution\n",n);
	}
	return 0;
}
