#include<stdio.h>
int main()
{
	int n,x,size;
	while(scanf("%d",&n)==1)
	{
		unsigned mask=1;
		size=8*sizeof(int)-1;
	//	printf("%d\n",size);
		mask=mask<<size;
		while(mask)
		{
			x=(mask & n)?1:0;
			printf("%d",x);
			mask=mask>>1;
		}
		printf("\n");
	}
	return 0;
}