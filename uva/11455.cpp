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
	int t,a[4];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
        if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])	
			printf("square\n");
		else
		{
			qsort(a,4,sizeof(int),cmp);
	        if(a[0]==a[1] && a[2]==a[3])
		    	printf("rectangle\n");
		    else if(a[0]+a[1]+a[2]>a[3])
			    printf("quadrangle\n");
		    else
			    printf("banana\n");
		}
	}
	return 0;
}
