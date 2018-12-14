#include<stdio.h>
int main()
{
	long dec,i,j,po[1000];
	char a[1000];
	while(1)
	{
		gets(a);
		if(a[0]=='0')
			break;
		po[1]=2;
		for(i=1;a[i]!='\0';i++)
		{
			po[i+1]=po[i]*2;
		}
		dec=0;
		for(j=0;j<i;j++)
		{
			dec+=(a[j]-'0')*(po[i-j]-1);
		}
		printf("%ld\n",dec);
	}
	return 0;
}
