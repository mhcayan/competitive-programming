#include<stdio.h>
int main()
{
	int t,c,a,b;
	scanf("%d",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%d %d",&a,&b);
		if(a>b)
			printf("Case %d: %d\n",t,19+(a-b+a)*4);
		else
			printf("Case %d: %d\n",t,19+b*4);
	}
	return 0;
}