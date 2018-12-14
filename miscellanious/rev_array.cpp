#include<stdio.h>
void rev(long,long);
long a[10000];
int main()
{
	long n,i;
	scanf("%ld",&n);
	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
	rev(0,n-1);
	for(i=0;i<n;i++)
		printf("%ld",a[i]);
	return 0;
}
void rev(long i,long j)
{
	long t;
	if(i<j)
	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		rev(i+1,j-1);
	}
}


