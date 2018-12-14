#include<stdio.h>
int main()
{
	long l,h,v,i,max,cl,n;
	while(scanf("%ld %ld",&l,&h))
	{
		if(l==0 && h==0)
			break;
		v=1;
		max=0;
		for(i=l;i<=h;i++)
		{
			cl=0;
			n=i;
			while(n!=1)
			{
				if(n%2)
					n=3*n+1;
				else
					n=n/2;
				cl++;
			}
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

