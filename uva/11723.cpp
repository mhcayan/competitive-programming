#include<stdio.h>
int main()
{
	long r,n,t=1,i,flag;
	while(scanf("%ld %ld",&r,&n)==2 && n&&r)
	{
		flag=1;
		for(i=0;i<=26;i++)
		{
			if(n*i+n>=r)
			{
				printf("Case %ld: %ld\n",t,i);
				flag=0;
				break;
			}
		}
		if(flag)
		{
			printf("Case %ld: impossible\n",t);
		}
		t++;
	}
	return 0;
}
