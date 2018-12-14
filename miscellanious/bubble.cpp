#include<stdio.h>
int main()
{
	int a[100],i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
		for(j=1;j<n-i;j++)
		{
			if(a[j]>a[j-1])
			{
				int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		return 0;
}
