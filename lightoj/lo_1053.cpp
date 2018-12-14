#include<stdio.h>
int main()
{
	int a,b,c,p,max,t=1,cas;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d %d %d",&a,&b,&c);
		max=a>b?a:b;
		max=max>c?max:c;
		p=-2*max*max;
		p=p+a*a+b*b;
		if(p+c*c==0)
			printf("Case %d: yes\n",t++);
		else
			printf("Case %d: no\n",t++);
	}
	return 0;
}
		
