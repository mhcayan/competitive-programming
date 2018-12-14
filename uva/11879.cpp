#include<stdio.h>
#include<stdlib.h>
int main()
{
	char s[10000],a[10000];
	int m,n,l;
	while(scanf("%s",s))
	{
		if(s[0]=='0')
			break;
		a[0]=s[0];
		a[1]=s[1];
		a[2]='\0';
		if(a[1]=='\0')
			l=1;
		else
			l=2;
		n=atoi(a);
		m=n%17;
		while(s[l])
		{
			n=m*10+s[l++]-'0';
			m=n%17;

		}
		if(m==0)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
