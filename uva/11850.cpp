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
	int n,a[1422],i,flag;
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		flag=1;
		if(n>7)
		{
			flag=0;
			qsort(a,n,sizeof(int),cmp);
	    	for(i=1;i<n;i++)
			{
				if((a[i]-a[i-1])>200)
				{
					flag=1;
				    break;
				}
			}
			if((1422-a[n-1])>100)
				flag=1;
		}
		if(flag)
			printf("IMPOSSIBLE\n");
		else
			printf("POSSIBLE\n");

	}
	return 0;
}
