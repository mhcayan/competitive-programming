#include<stdio.h>
void print(int *a,int i,int j);
int main()
{
	int a[100],i,n;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		print(a,0,n-1);
	}
	return 0;
}
void print(int *a,int i,int j)
{
	if(i>j)
		return;
	printf("%d %d\n",a[i],a[j]);
	print(a,i+1,j-1);
}
