#include<stdio.h>
int main()
{
	int n,a,b,c,flag,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		flag=0;
		scanf("%d %d %d",&a,&b,&c);
		if(a+b>c)
		{
			if(a+c>b)
			{
				if(b+c>a)
				{
					flag=1;
				}
			}
		}
		if(flag)
			printf("OK\n");
		else
			printf("Wrong!!\n");
	}
	return 0;
}