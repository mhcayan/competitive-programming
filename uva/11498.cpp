#include<stdio.h>
int main()
{
	long a,b,q,i,x,y;
	while(scanf("%ld",&q))
	{
		if(q==0)
			break;
		scanf("%ld %ld",&a,&b);
		for(i=0;i<q;i++)
		{
			scanf("%ld %ld",&x,&y);
			if(x==a || y==b)
				printf("divisa\n");
			else
			{
				x=x-a;
				y=y-b;
				if(x>0 && y>0)
					printf("NE\n");
				else if(x>0 && y<0)
					printf("SE\n");
				else if(x<0 && y<0)
					printf("SO\n");
				else 
					printf("NO\n");
			}
		}
	}
	return 0;
}