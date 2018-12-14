#include<stdio.h>
int main()
{  
	int c,t,p,n;
	scanf("%d",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%d",&n);
		p=0;
		while(n)
		{
			if(n%2)
				p++;
			n/=2;
		}
		if(p%2)
			printf("Case %d: odd\n",t);
		else
			printf("Case %d: even\n",t);
	}
	return 0;
}
