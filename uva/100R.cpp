#include<stdio.h>
int main()
{
	long a,b,i,cl,max,n;
	while(scanf("%ld %ld",&a,&b)==2)
	{
		max=1;
		for(i=a;i<=b;i++)
		{
			n=i;
			cl=1;
			while(n!=1)
			{
				if(n%2)
					n=3*n+1;
				else
					n=n/2;
				cl++;
			}
			if(cl>max)
				max=cl;
		}
		printf("%ld %ld %ld\n",a,b,max);
	}
	return 0;
}















