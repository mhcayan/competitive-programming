#include<stdio.h>
int main()
{
	int t,a,b,sum,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d",&a,&b);
		if(a%2==0)
			a++;
		sum=0;
		while(a<=b)
		{
			sum+=a;
			a+=2;
		}
		printf("Case %d: %d\n",i,sum);
	}
	return 0;
}

