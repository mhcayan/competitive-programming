#include<stdio.h>
int main()
{
	long n,i,value,b,e,m,a[100];
	while(scanf("%ld",&n)==1)
	{
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		while(scanf("%ld",&value)==1)
		{
			b=1;
			e=n;
			while(b<=e)
			{
				m=(b+e)/2;
				if(value<=a[m])
					e=m-1;
				else
					b=m+1;
			}
			if(a[b]==value)
				printf("%ld\n",b);
			else
				printf("not found\n");
		}
	}
	return 0;
}

