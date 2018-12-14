#include<stdio.h>
#include<string.h>
int main()
{
	char s[150],sum[150]="0",a[150];
	int car,i=0,l1,l2,val;
	while(gets(s))
	{
		if(s[0]=='0')
			break;
		l1=strlen(s);
		l2=strlen(sum);
		for(i=0;i<l1;i++)
			a[i]=s[l1-1-i];
		car=0;
		for(i=0;i<l1 && i<l2;i++)
		{
			val=a[i]-'0'+sum[i]-'0'+car;
			sum[i]=val%10+'0';
			car=val/10;
		}
		if(i==l1)
		{
			for(;i<l2;i++)
			{
				val=sum[i]-'0'+car;
                sum[i]=val%10+'0';
				car=val/10;
			}
		}
		else
		{
			for(;i<l1;i++)
			{
				val=a[i]-'0'+car;
				sum[i]=val%10+'0';
				car=val/10;
			}
		}
		if(car)
			sum[i++]=car+'0';
		sum[i]='\0';
		//printf("%s\n",sum);
	}
	if(i>0)
	{
		for(l1=0;l1<i;l1++)
			s[l1]=sum[i-1-l1];
	    s[l1]='\0';
	    printf("%s\n",s);
	}
	else
		printf("0\n");
	return 0;
}
