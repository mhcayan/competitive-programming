#include<stdio.h>
#include<stdlib.h>
int a[2000000];
int cmp(const void *a,const void *b)
{
	int *x=(int*)a;
	int *y=(int*)b;
	return *x-*y;
}
int main()
{
	long i,n;
	while(scanf("%ld",&n))
	{
		if(!n)
			break;
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		qsort(a,n,sizeof(int),cmp);
		n--;
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[i]);
	}
	return 0;
}

