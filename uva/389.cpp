#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[100],a[100],str[200];
	long i,sum,mul,l,b1,b2,d;
	while(gets(str))
	{
		sscanf(str,"%s %ld %ld",s,&b1,&b2);
		l=strlen(s)-1;
		for(i=l;i>-1;i--)                      //REVERSING THE GIVEN STRING TO CONVERT IT IN ITS EQUIVALENT DECIMAL(BASE 10) EASILY
		{
			if(s[i]>='0'&&s[i]<='9')
				a[l-i]=s[i]-'0';
			else
				a[l-i]=s[i]-55;
		}
		if(b1!=10)                          //IF THE GIVEN NO. IS NOT IN BASE 10
		{
			sum=0;                          //THEN CONVERT IT IN ITS EQUIVALENT DECIMAL(BASE 10) NO.
			mul=1;
			for(i=0;i<=l;i++)
			{
				sum+=a[i]*mul;
				mul*=b1;
			}
		}
		else
		{
			sum=atol(s);
		}
		if(b2==10)
		{
			if(sum>9999999)
				printf("  ERROR\n");
			else
				printf("%7ld\n",sum);
		}
		else if(sum==0)
			printf("      0\n");
		else
		{
			i=-1;
			int flag=0;
		    while(sum)
			{
				if(i==6)            //THIS CONDITION IS TO CHECK WHETHER THE OUTPUT CROSS THE 7-DIGIT DISPLAY
				{
					flag=1;
					break;
				}
				d=sum%b2;
			    sum/=b2;
			    if(d>=0 && d<=9)
					a[++i]=d+'0';
			    else
				    a[++i]=d+55;
			}
			if(flag)
				printf("  ERROR\n");
			else
			{
				for(l=0;l<=i;l++)
				{
					s[l]=a[i-l];
				}
		        s[l]='\0';
		        printf("%7s\n",s);
			}
		}		 
	}
	return 0;
}
		
		