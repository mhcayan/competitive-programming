#include<stdio.h>
#include<math.h>
int main()
{
	char a[30],status;
	int i,sum,s;
	while(gets(a))
	{
		sum=0;
		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]>96)
				sum+=a[i]-96;
			else
				sum+=a[i]-38;
		}
		status=1;
		if(sum==2)
		{
		}
		else if(sum%2==0)
			status=0;
		else
		{
			s=sqrt(sum);
			for(i=3;i<=s;i+=2)
			{
				if(sum%i==0)
				{
					status=0;
					break;
				}
			}
		}
		if(status)
			printf("It is a prime word.\n");
		else
			printf("It is not a prime word.\n");
	}
	return 0;
}