//finding the index of last element which is equel to value
#include<stdio.h>
int main()
{
	long n,i,a[100],b,e,m,value;
	while(scanf("%ld",&n)==1)
	{
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		while(scanf("%ld",&value)==1)
		{
		    b=1,e=n;
		    while(b<=e)
			{
			    m=(b+e)/2;
			    if(value>=a[m])
					b=m+1;
				else
					e=m-1;
				//printf("%ld %ld %ld\n",b,e,m);
			}
			if(a[e]==value)
				printf("%d\n",e);
			else
				printf("not found\n");
		}
	}
	return 0;
}
