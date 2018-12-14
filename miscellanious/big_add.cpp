#include<stdio.h>
#include<string.h>
int rev(char *from,char *to)
{
	int l,i;
	l=strlen(from)-1;
	for(i=0;i<=l;i++)
		to[i]=from[l-i];
	to[i]='\0';
	return 0;
}
int sum(char *p,char *q,char *c)
{
	char res[100],a[100],b[100];
	int inhand,i,sum;
	rev(p,a);
	rev(q,b);
	inhand=0;
	for(i=0;a[i]&&b[i];i++)
	{
		sum=a[i]-'0'+b[i]-'0'+inhand;
		res[i]=sum%10+'0';
		inhand=sum/10;
	}
	if(a[i])
	{
	    for(;a[i];i++)
		{
		    sum=a[i]-'0'+inhand;
		    res[i]=sum%10+'0';
		    inhand=sum/10;
		}
	}
	else
	{
	    for(;b[i];i++)
		{
		    sum=b[i]-'0'+inhand;
		    res[i]=sum%10+'0';
		    inhand=sum/10;
		}
	}
	if(inhand)
		res[i++]=inhand+'0';
	res[i]='\0';
	rev(res,c);
	return 0;
}
int main()
{
	char a[100],b[100],c[100];
	while(gets(a))
	{
		gets(b);
		sum(a,b,c);
		printf("%s\n",c);
	}
	return 0;
}
