#include<stdio.h>
#include<stdlib.h>
int main()
{
	long t,i,c,sum,n;
	char a[1000];
	scanf("%ld",&c);
	getchar();
	for(t=1;t<=c;t++)
	{
		gets(a);
		n=atol(a);
		sum=0;
		while(1)
		{
			sum=0;
			for(i=0;a[i];i++)
			{
				a[i]=a[i]-'0';
				sum+=a[i]*a[i];
			}
			if(sum==1 || sum==4)
				break;
			i=0;
			while(sum)
			{
				a[i++]=sum%10+'0';
				sum=sum/10;
			}
			a[i]='\0';   
		}
		if(sum==1)
			printf("Case #%ld: %ld is a Happy number.\n",t,n);
		else
			printf("Case #%ld: %ld is an Unhappy number.\n",t,n);
	}
	return 0;
}
		