#include<stdio.h>
int main()
{
	long a[10000],i,j,k,nr,pr,max;
	while(1)
	{
		max=0;
		i=-1;
	    do
		{
		    scanf("%ld",&a[++i]);
		    if(a[i]>0)
			{
			    if(a[i]>max)
				    max=a[i];
			}
			else
			{
				if(-a[i]>max)
					max=-a[i];
			}
		}while(a[i]);
	    if(a[0]==0)
		    break;
		for(j=max;j>=1;j--)
		{
			pr=a[0]%j;
			if(pr<0)
				pr=-pr+1;
			for(k=1;k<i;k++)
			{
				nr=a[k]%j;
				if(nr<0)
					nr=-nr+1;
				if(pr!=nr)
					break;
			}
			if(k==i)
			{
				printf("%ld\n",j);
				break;
			}
		}
	}
	return 0;
}



	
