#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int l,i,j;
	while(gets(a))
	{
		l=strlen(a);
		for(i=0;i<=l;i++)
		{
			if(a[i]==' '||a[i]=='\0')
			{
				j=i-1;
				while(j>=0 && a[j]!=' ')
				{
					printf("%c",a[j]);
					j--;
				}
				if(a[i]=='\0')
				   printf("\n");
				else
					printf("%c",a[i]);
			}
		}
	}
	return 0;
}
