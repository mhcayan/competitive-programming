#include<stdio.h>
#include<math.h>
int main()
{
	long t,l,u,maxd,i,j,max,d,k,s;
	scanf("%ld",&t);
	while(t!=0)
	{
		scanf("%ld %ld",&l,&u);
		k=u/2+1;

		if(k<=l)
			k=l;
		i=u;
		if(u%2!=0 && u>l)
			i--;
		maxd=1;
		max=1;
		while(i>=k)
		{
			d=0;
            s=sqrt(i);
			for(j=s;j>=1;j--)
			{
				if(i%j==0)
				{
					d++;
					if(j!=s)
						d++;
				}
				
			}
			if(i==1)
				d--;
			if(d>=maxd)
			{
				max=i;
				maxd=d;
			}
			i=i-2;

		}
		printf("Between %ld and %ld,%ld has maximum of %ld divisors.\n",l,u,max,maxd);
		t--;
	}
	return 0;
}

			
