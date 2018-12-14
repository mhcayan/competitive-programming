#include<stdio.h>
int main()
{
	int n,j,i,v,x,l,c,m,a;
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		i=v=x=l=c=0;
		m=n;
		if(n==100)
		{
			c=1;
			m--;
		}
		j=n;
		for(j=1;j<=m;j++)
		{
			a=j%10;
			if(a==4)
			{
				i++;
				v++;
			}
			else if(a==9)
			{
				i++;
				x++;
			}
			else
			{
				v+=a/5;
				i+=a%5;
			}
			a=j-a;
			if(a==40)
			{
				x++;
				l++;
			}
			else if(a==90)
			{
				x++;
				c++;
			}
			else
			{
				l+=a/50;
				x+=(a%50)/10;
			}
		}
		printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,i,v,x,l,c);
	}
	return 0;
}
			