#include<stdio.h>
#include<stdlib.h>
int main()
{
	int r1,r2,c1,c2;
	while(scanf("%d %d %d %d",&r1,&c1,&r2,&c2))
	{
		if(r1==0)
			break;
		if(r1==r2 && c1==c2)
			printf("0\n");
		else if(r1==r2 || c1==c2 ||abs(r1-r2)==abs(c1-c2))
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}