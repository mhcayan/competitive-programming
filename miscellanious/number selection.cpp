#include<stdio.h>
int main()
{
	int num,vagsesh;
	scanf("%d",& num);
	vagsesh=num%2;
	if(vagsesh==0)
	{
		printf("%d,is an even number",num);
	}
	else{
		printf("%d,is an odd number",num);
	}
	printf("good bye\n");
}
