#include<stdio.h>
int main()
{
	long n,t=0;
	while(1)
	{
		scanf("%ld",&n);
		if(n<0)
			break;
		t++;
		p=0;
		i=1;
		while(1)
		{
			i*=2;
			if(i>n)
				break;
			p++;
		}
		printf("Case %ld: %ld.\n",t,p);
	}
	return 0;
}

			
