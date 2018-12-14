#include<stdio.h>
#include<math.h>
int main()
{
	long a[40],t,i,j,k,sum,f,temp;
	scanf("%ld",&t);
	while(t)
	{
		i=0;
		while(scanf("%ld",&a[i]))
		{
			if(a[i]==0)
				break;
			i++;
		}
		for(j=0;j<i-1;j++)
		{
			f=1;
			for(k=1;k<i-j;k++)
			{
				if(a[k]>a[k-1])
				{
					temp=a[k];
					a[k]=a[k-1];
					a[k-1]=temp;
					f=0;
				}
			}
            if(f)
				break;
		}
		sum=0;
		for(j=0;j<i;j++)
		{
			sum+=2*pow(a[j],j+1);
			if(sum>5000000)
				break;
		}
		if(sum>5000000)
			printf("Too expensive\n");
		else
			printf("%ld\n",sum);
		t--;
	}
	return 0;
}


	