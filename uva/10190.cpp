#include<stdio.h>
int main()
{
	char flag;
	long n,m,a[1000],i;
	while(scanf("%ld %ld",&n,&m)==2)
	{
		if(m==1||m==0||n==1||n==0)
			printf("Boring!\n");
		else
		{
			flag=0;
	    	i=0;
		    a[0]=n;
			while(a[i]!=1)
			{
				if(a[i]%m)
				{
					flag=1;
					break;
				}
				else
				{
					a[++i]=a[i]/m;
				}
			}
			
		    if(flag)
				printf("Boring!\n");
		    else
			{
			    for(m=0;m<i;m++)
					printf("%ld ",a[m]);
			    printf("%ld\n",a[m]);
			}
		}
	}
	return 0;
}

