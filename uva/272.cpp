#include<stdio.h>
int main()
{
	char a[1000],b[1000];
	long i,flag=1,j;
	while(gets(a))
	{
		j=0;
		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]=='"')
			{
				if(flag%2)
				{
					b[j++]='`';
					b[j++]='`';
				}
				else
				
				{
					b[j++]='\'';
					b[j++]='\'';
				}
				flag++;
			}
			else
				b[j++]=a[i];
		}
		b[j]='\0';
		printf("%s\n",b);
	}
	return 0;
}

