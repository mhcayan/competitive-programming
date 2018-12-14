#include<stdio.h>
int main()
{
	int c,t,d1,d2,m1,m2,y1,y2,year;
	char s1[30],s2[30];
	scanf("%d",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%s",s1);
		sscanf(s1,"%d/%d/%d",&d1,&m1,&y1);
		scanf("%s",s2);
		sscanf(s2,"%d/%d/%d",&d2,&m2,&y2);
		printf("Case #%d: ",t);
		if(y2>y1)
			printf("Invalid birth date\n");
		else if(y2==y1)
		{
			if(m2>m1)
				printf("Invalid birth date\n");
			else if(m2==m1)
			{
				if(d2>d1)
					printf("Invalid birth date\n");
				else
					printf("0\n");
			}
			else
				printf("0\n");
		}
		else
		{
			year=y1-y2;
			if(m2>m1)
				year--;
			else if(m2==m1)
			{
				if(d2>d1)
					year--;
			}
			bool flag=1;
			if(year>130)
			{
				printf("Check birth date\n");
				flag=0;
			}
			else if(year==130)
			{
				if(m1>m2)
				{
					printf("Check birth date\n");
					flag=0;
				}
				else if(m1==m2)
				{
					if(d1>=d2)
					{
						printf("Check birth date\n");
						flag=0;
					}
				}
			}
			if(flag)
				printf("%d\n",year);

		}
	}
	return 0;
}