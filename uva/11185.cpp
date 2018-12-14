#include<stdio.h>
int main()
{
	char a[100],b[100];
	long n,i,j;
	while(1)
	{
		scanf("%ld",&n);
		if(n<0)
			break;
		else if(n==0)
			printf("%ld\n",n);
		else
		{
			i=-1;
			while(n)
			{
				i++;
				a[i]=n%3+'0';
				n=n/3;
			}
			for(j=0;j<=i;j++)
				b[j]=a[i-j];
	       	b[j]='\0';
	    	printf("%s\n",b);
		}
		
	}
	return 0;
}

