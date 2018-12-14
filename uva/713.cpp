#include<stdio.h>
#include<string.h>
int add(char *a,char *b)
{
	char s[10000];
	long l1,l2,l,i,sum,hold;
	l1=strlen(a);
	l2=strlen(b);
	l=l1<l2?l1:l2;
	hold=0;
	for(i=0;i<l;i++)
	{
		sum=a[i]-'0'+b[i]-'0'+hold;
		s[i]=sum%10+'0';
		hold=sum/10;
	}
	if(l==l1)
	{
		for(;i<l2;i++)
		{
			sum=b[i]-'0'+hold;
			s[i]=sum%10+'0';
			hold=sum/10;
		}
	}
	else
	{
		for(;i<l1;i++)
		{
			sum=a[i]-'0'+hold;
			s[i]=sum%10+'0';
			hold=sum/10;
		}
	}
	if(hold)
	{
		s[i]=hold+'0';
		s[++i]='\0';
	}
	else
		s[i]='\0';
	l=i;
	for(i=0;s[i]=='0';i++);
	if(s[i]=='\0')
		strcpy(a,"0");
	else
	{
		int t=0;
		for(;i<=l;i++)
		{
			a[t++]=s[i];
		}
	}
	puts(a);
	return 0;
}

int main()
{
	char a[10000],b[10000];
	long t;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s %s",a,b);
		add(a,b);
	}
	return 0;
}