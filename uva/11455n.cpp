#include<stdio.h>
int main()
{
	int t,a[4],max,min,p,q,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
		if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3])
			printf("square\n");
		else
		{
			max=min=a[0];
			for(i=1;i<4;i++)
			{
				if(a[i]>max)
					max=a[i];
				if(a[i]<min)
					min=a[i];
			}
			p=q=0;
			for(i=0;i<4;i++)
			{
				if(max==a[i])
					p++;
				else if(min==a[i])
					q++;
			}
			if(p==2&&q==2)
				printf("rectangle\n");
			else if(a[0]+a[1]+a[2]+a[3]-max>max)
				printf("quadrangle\n");
			else
				printf("banana\n");
		}
	}
	return 0;
}
				
