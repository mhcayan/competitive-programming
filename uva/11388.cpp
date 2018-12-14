#include<stdio.h>
#include<math.h>
int main()
{
	long t,g,l,m,s,lcm,j,a,b,c,k,flag;
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%ld %ld",&g,&l);
		if(g>l)
			printf("-1\n");
		else
		{
			m=g*l;
			s=sqrt(m);
			a=g;
			k=2;
			flag=0;
			while(a<=s)
			{
				if(m%a==0)
				{
					lcm=b=m/ a;
					j=2;
					while(lcm<l)
					{
						if(lcm%a==0)
							break;
						lcm=b*j;
						j++;
					}
					if(lcm==l)
					{
						if(lcm%a==0)
						{
							printf("%ld %ld\n",a,b);
							flag=1;
						}
					}
				}
				if(flag)
					break;
				a=g*k;
				k++;
			}
			if(flag==0)
				printf("-1\n");
		}
	}
	return 0;
}
