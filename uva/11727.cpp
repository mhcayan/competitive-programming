#include<stdio.h>
int main()
{
	int t,a,b,c,mid,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(b>a)
		{
			if(b<c)
				mid=b;
			else if(c>a)
				mid=c;
			else
				mid=a;
		}
		else
		{
            if(a<c)
				mid=a;
			else if(c>b)
				mid=c;
			else
				mid=b;
		}
		printf("Case %d: %d\n",i,mid);
	}
	return 0;
}

