#include<stdio.h>
#include<math.h>
int main()
{
	long s,n,p,a;
	while(scanf("%ld",&s)&&s!=-1)
	{
		p=2*s;
		for(n=sqrt(p);n>0;n--)
		{
			if(p%n!=0)
				continue;
			p=p/n-n+1;
			if(p%2!=0)
			{
				p=2*s;
				continue;
			}
			a=p/2;
			break;
		}
		printf("%ld = %ld + ... + %ld\n",s,a,a+n-1);
	}
	return 0;
}

