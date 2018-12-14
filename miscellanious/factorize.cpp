#include<stdio.h>
int main()
{
	int a[3]={2,3,5},n,i;
	while(scanf("%d",&n)==1)
	{
	    for(i=0;i<3;i++)
		{
		    while(n%a[i]==0)
			{
			    n=n/a[i];
			}
		}
	    printf("%d\n",n);
	}
	return 0;
}
