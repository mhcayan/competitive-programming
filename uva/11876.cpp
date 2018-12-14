#include<stdio.h>
#include<math.h>
int main()
{
	long t,p,i,j,k,s,sd,a,b;
	scanf("%ld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%ld %ld",&a,&b);
		p=1;
		j=2;
		while(1)
		{
			sd=j+1;
			s=sqrt(j);
			for(k=2;k<s;k++)
			{
				if(j%k==0)
					sd+=k;
			}
			if(s*s==j)
				sd+=s;
			j+=sd;
			if(j>b)
				break;
			p++;
		}
		printf("Case %ld: %ld\n",i,p);
	}
	return 0;
}