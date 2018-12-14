#include<stdio.h>
int main()
{
	int t,i,j,k,a,f;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&f);
		for(k=0;k<f;k++)
		{
			for(i=1;i<=a;i++)
			{
				for(j=1;j<=i;j++)
				{
					printf("%d",i);
				}
				printf("\n");
			}
			for(i=a-1;i>0;i--)
			{
				for(j=1;j<=i;j++)
				{
					printf("%d",i);
				}
				printf("\n");
			}
			if(k!=f-1)
				printf("\n");
		}
		if(t)
			printf("\n");
	}
	return 0;
}

