#include<stdio.h>
#include<math.h>
int main()
{
	long n,b,e,m;
	long double k,v,p;
	while(scanf("%ld %Lf",&n,&p)==2)
	{
		b=1;e=1000000000;
		m=(b+e)/2;
		while(1)
		{
			v=pow(m,n);
			if(v==p)
			{
				k=m;
				break;
			}
			else if(v>p)
			{
				e=m-1;
				m=(b+e)/2;
			}
			else
			{
				b=m+1;
				m=(b+e)/2;
			}
		}
		printf("%ld\n",(long)k);
	}
	return 0;
}

