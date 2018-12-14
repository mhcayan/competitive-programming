#include<stdio.h>
int rec(int i,int j,int *a,int &n);
int main()
{
	int a[100],i,n;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		rec(0,0,a,n);
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
int rec(int i,int j,int *a,int &n)
{
	if(i==n)
	{
		n=j;
		return 0;
	}
	if(a[i]%2==0)
		a[j++]=a[i];
	rec(i+1,j,a,n);
	return 0;
}