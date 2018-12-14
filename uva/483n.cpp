#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000],b[1000];
	int i,j,k,l;
	while(gets(a))
	{
		l=strlen(a);
		k=0;
		for(i=0;i<=l;i++)
		{
			if(a[i]==' ' || a[i]=='\0')
			{
				j=i-1;
				while(j>-1 && a[j]!=' ')
				{
					b[k]=a[j];
					k++;
					j--;
				}
				if(a[i]==' ')
				{
					b[k]=' ';
					k++;
				}
				else
					b[k]='\0';
			}
		}
		printf("%s\n",b);
	}
	return 0;
}

