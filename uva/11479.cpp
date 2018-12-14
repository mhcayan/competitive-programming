#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	int *x=(int*)a;
	int *y=(int*)b;
	return *x-*y;
}
int main()
{
	long t,a[3],c;
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%ld %ld %ld",&a[0],&a[1],&a[2]);
		qsort(a,3,sizeof(long),cmp);
		if(a[0]+a[1]>a[2])
		{
			if(a[0]==a[2])
				printf("Case %ld: Equilateral\n",t);
			else if(a[0]==a[1] || a[1]==a[2])
				printf("Case %ld: Isosceles\n",t);
			else
				printf("Case %ld: Scalene\n",t);
		}
		else
			printf("Case %ld: Invalid\n",t);
	}
	return 0;
}
