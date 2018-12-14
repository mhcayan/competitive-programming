#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	long *x=(long*)a;
	long *y=(long*)b;
	return *x-*y;
}
int main()
{
	long a[3];
	while(1)
	{
		scanf("%ld %ld %ld",&a[0],&a[1],&a[2]);
		if(a[0]==0)
			break;
		qsort(a,3,sizeof(long),cmp);
		printf("%ld %ld %ld\n",a[0],a[1],a[2]);
		if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
			printf("right\n");
		else
			printf("wrong\n");
	}
	return 0;
}
