#include<stdio.h>
int main()
{
	int n,num,i,j,sum;
	char s[20],a[20];
	scanf("%ld",&n);
	getchar();
	while(n--)
	{
		sum=j=0;
		gets(s);
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]!=' ')
				a[j++]=s[i];
		}
		for(i=0;i<j;i++)
		{
			if(i%2==0)
			{
				num=2*(a[i]-'0');
				sum+=num%10+num/10;
			}
			else
				sum+=a[i]-'0';
		}
		if(sum%10==0)
			printf("Valid\n");
		else
			printf("Invalid\n");
	}
	return 0;
}


