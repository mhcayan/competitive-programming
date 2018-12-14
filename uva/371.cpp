#include<stdio.h>
int main()
{
	long l,h,v,i,max,cl,n,a,b;
	while(scanf("%ld %ld",&a,&b)==2)
	{
		if(a==0 && b==0)
			break;
		if(a>=b)
		{
			l=b;
			h=a;
		}
		else
		{
			l=a;
			h=b;
		}
		max=0;
		for(i=l;i<=h;i++)
		{
			cl=0;
	     	n=i;
		   	do
			{
				if(n%2)
					n=3*n+1;
				else
				    n=n/2;
			    cl++;
			}while(n!=1);
		    if(cl>max)
			{
				max=cl;
			    v=i;
			}
		}
		printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",l,h,v,max);
	}
	return 0;
}

