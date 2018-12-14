#include<stdio.h>
int main()
{
	int n,i,p,c=0;
	while(scanf("%d",&n))
	{
		if(n<0)
			break;
		c++;
		i=1;
		p=0;
		while(i<n)
		{
			i=i*2;
			p++;
		}
		printf("Case %d: %d\n",c,p);
	}
	return 0;
}

			
	
		