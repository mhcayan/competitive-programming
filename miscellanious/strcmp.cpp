#include<stdio.h>
#include<stdlib.h>
int cmpstr(char a[100],char b[100])
{
	for(int i=0;a[i] && b[i];i++)
	{
		if(toupper(a[i])>toupper(b[i]))
			return 1;
		else if(toupper(a[i])<toupper(b[i]))
			return -1;
	}
	if(a[i]=='\0' && b[i]=='\0')
		return 0;
	else if(b[i]=='\0')
		return 1;
	else 
		return -1;
}
int main()
{
	char a[100],b[100];
	while(gets(a))
	{
		gets(b);
		printf("%d\n",cmpstr(a,b));
	}
	return 0;
}
