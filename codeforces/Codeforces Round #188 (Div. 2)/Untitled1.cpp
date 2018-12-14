#include<stdio.h>
#include<string.h>
int main()
{
	char a[10100],h[]="abc";
	int i;
	while(scanf("%s",a)==1)
	{
		for(i=0;a[i];i++)
		{
			if(strncmp(a+i,h,3)==0)
			   printf("yes\n");
		}
	}
}
