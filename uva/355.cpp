#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[100],s[100],str[100];
	long p,q,i,sum,l,mul,d,flag;
	while(gets(str))
	{
		sscanf(str,"%ld %ld %s",&p,&q,s);
		l=strlen(s);
		for(i=0;s[i];i++)
		{
			if(s[i]>='0' && s[i]<='9')
				a[--l]=s[i]-'0';
			else
				a[--l]=s[i]-55;
		}
		flag=0;
		for(i=0;s[i];i++)
		{
			if(a[i]>=p)
			{
				flag=1;
				break;
			}
		}
		if(flag)
			printf("%s is an illegal base %ld number\n",s,p);
		else
		{
			if(p==10)
				sum=atol(s);
			else
			{
				sum=0;
			    mul=1;
			    for(i=0;s[i];i++)
				{
					sum+=a[i]*mul;
				    mul*=p;
				}
			}
			if(sum==0)
				printf("0 base %ld = 0 base %ld\n",p,q);
			else if(q==10)
			{
				printf("%s base %ld = %ld base %ld\n",s,p,sum,q);
			}
		    else
			{
				l=-1;
				while(sum)
				{
					d=sum%q;
					sum/=q;
					if(d<10)
						str[++l]=d+'0';
					else
						str[++l]=d+55;
				}
				for(i=0;i<=l;i++)
					a[i]=str[l-i];
				a[i]='\0';
				printf("%s base %ld = %s base %ld\n",s,p,a,q);
			}
			
		}
	}
	return 0;
}
				

