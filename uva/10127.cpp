#include<stdio.h>
#include<stdlib.h>
int main()
{
	char m[20];
	long n,i,a;
	while(gets(m))
	{
		n=atol(m);
		for(i=0;m[i];i++)
			m[i]='1';
		m[i]='\0';
		a=atol(m);
		while(1)
		{
			a=a%n;
			if(a==0)
				break;
			a=a*10+1;
			i++;
		}
		printf("%ld\n",i);
	}
	return 0;
}