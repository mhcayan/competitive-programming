#include<stdio.h>
int main()
{
	long a,z,i,l,m,c,t;
	t=0;
	while(1)
	{
        scanf("%ld %ld %ld %ld",&z,&i,&m,&l);
		if(z==0 && i==0 && m==0 && l==0)
			break;
		else
		{
			c=0;
			t++;
			l=(z*l+i)%m;
			a=l;
			while(1)
			{
				l=(z*l+i)%m;
				c++;
				if(l==a)
					break;
			}
			printf("Case %ld: %ld\n",t,c);
		}
	}
	return 0;
}
