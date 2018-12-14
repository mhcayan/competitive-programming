#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[1000],b[1000],status;
	long n,i,r,m,l;
	while(gets(a))
	{
		n=atol(a);
		status=1;
		if(n==2)
		{
		}
		else if(n%2==0)
			status=0;
		else
		{
			r=sqrt(n);
			for(i=3;i<=r;i+=2)
			{
				if(n%i==0)
				{
					status=0;
					break;
				}
			}
		}
		if(status)
		{
			l=strlen(a)-1;
			for(i=0;i<=l;i++)
				b[i]=a[l-i];
			b[l+1]='\0';
			m=atol(b);
			if(m==n)
			{
			}
			else if(m%2==0)
			{
			}
			else
			{
				r=sqrt(m);
				for(i=3;i<=r;i+=2)
				{
					if(m%i==0)
						break;
				}
				if(i>r)
					status=2;
			}
		}
		if(!status)
			printf("%ld is not prime.\n",n);
		else if(status==1)
			printf("%ld is prime.\n",n);
		else
			printf("%ld is emirp.\n",n);
	}
	return 0;
}


			
