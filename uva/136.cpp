#include<stdio.h>
int main()
{
	long a[3]={2,3,5},i,j,k=1,u[2000],n;
	u[k]=1;
	for(i=2;i<1000000000;i++)
	{
		n=i;
		for(j=0;j<3;j++)
		{
			while(n%a[j]==0)
			{
				n=n/a[j];
			}
		}
		if(n==1)
		{
			u[++k]=i;
			if(k==1500)
				break;
		}
	}
	printf("%ld\n",u[k]);
	return 0;
}