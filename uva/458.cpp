#include<stdio.h>
int main()
{
	char s[20000],a[20000];
	long i;
	while(gets(s))
	{
		for(i=0;s[i];i++)
			a[i]=s[i]-7;
		a[i]='\0';
		printf("%s\n",a);
	}
	return 0;
}