#include<stdio.h>
int main()
{
	int h1,m1,h2,m2,u,l,s;
	while(scanf("%d %d %d %d",&h1,&m1,&h2,&m2))
	{
		if(h1==0&&m1==0&&h2==0&&m2==0)
			break;
		else
		{
			l=h1*60+m1;
			u=h2*60+m2;
			if(u>l)
				s=u-l;
			else
				s=1440-l+u;
			printf("%d\n",s);
		}
	}
	return 0;
}


