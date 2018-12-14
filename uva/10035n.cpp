#include<stdio.h>
#include<string.h>
int main()
{
	char a[10],b[10],t[30];
	int i,c,co,n1,n2,s;
	while(1)
	{
		gets(c);
		for(i=0;c[i]!='\0';i++)
		{
			if(c[i]!=' ')
				a[i]=c[i];

		
		if(a[0]=='0'&&b[0]=='0')
			break;
		strrev(a);
		strrev(b);
		i=0;
		c=co=0;
		while(1)
		{
			if(a[i]=='\0' && b[i]=='\0')
				break;
			n1=a[i]-47;
			n2=b[i]-47;
			s=n1+n2+c;
			c=s/10;
			if(c)
				co++;
			i++;
		}
		if(co)
			printf("%d carry operation.\n",co);
		else
			printf("No carry operation.\n");
	}
	return 0;
}
