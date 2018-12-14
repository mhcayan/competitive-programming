#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n;
	time_t t;
	scanf("%d",&n);
	srand((unsigned) time(&t));
	for(int i=0;i<n;i++)
	{
		printf("%d ",rand()%36);
	}
	return 0;
}