//index of first element of a which is>value 
#include<stdio.h>
int main()
{
	int n,i,value,b,e,m,a[100];
	while(scanf("%d",&n)==1)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		while(scanf("%d",&value)==1)
		{
			b=1;
			e=n;
			//m=(b+e)/2;
			while(b<=e)
			{
				m=(b+e)/2;
				if(value<=a[m])
					e=m-1;
				else
					b=m+1;
			}
			printf("%d\n",e);
		}
	}
	return 0;
}

