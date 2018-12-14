#include<stdio.h>
#include<string.h>
char *add(char a[100],char b[100]);
int main()
{
	char a[100],b[100],res[100];
	while(gets(a))
	{
		gets(b);
		strcpy(res,add(a,b));
		printf("%s\n",res);
	}
	return 0;
}
char* add(char *a,char *b)
{
	int l,i,sum,inhand=0;
	char c[100],d[100],res[100];
	l=strlen(a)-1;
	for(i=0;i<=l;i++)
		c[i]=a[l-i];
	c[i]='\0';
	l=strlen(b)-1;
	for(i=0;i<=l;i++)
		d[i]=b[l-i];
	d[i]='\0';
	for(i=0;c[i]!='\0' && d[i]!='\0';i++)
	{
		sum=(c[i]-'0')+(d[i]-'0')+inhand;
		res[i]=sum%10+'0';
		inhand=sum/10;
	}
	if(c[i]=='\0')
	{
		for(;d[i]!='\0';i++)
		{
			sum=(d[i]-'0')+inhand;
			res[i]=(sum%10)+'0';
			inhand=sum/10;
		}
	}
    else if(d[i]=='\0')
	{
		for(;c[i]!='\0';i++)
		{
			sum=(c[i]-'0')+inhand;
			res[i]=(sum%10)+'0';
			inhand=sum/10;
		}
	}
	if(inhand)
		res[i++]=inhand+'0';
	printf("%d\n",inhand);
	l=i-1;
	for(i=0;i<=l;i++)
	{
		a[i]=res[l-i];
	}
	a[i]='\0';
	//printf("%s\n",a);
	return a;
}
		
