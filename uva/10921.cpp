#include<stdio.h>
int main()
{
	char a[31],b[31],i;
	while(gets(a))
	{
		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]=='A'||a[i]=='B'||a[i]=='C')
				b[i]='2';
            else if(a[i]=='D'||a[i]=='E'||a[i]=='F')
				b[i]='3';
            else if(a[i]=='G'||a[i]=='H'||a[i]=='I')
				b[i]='4';
            else if(a[i]=='J'||a[i]=='K'||a[i]=='L')
				b[i]='5';
            else if(a[i]=='M'||a[i]=='N'||a[i]=='O')
				b[i]='6';
            else if(a[i]=='P'||a[i]=='Q'||a[i]=='R'||a[i]=='S')
				b[i]='7';
            else if(a[i]=='T'||a[i]=='U'||a[i]=='V')
				b[i]='8';
            else if(a[i]=='-'||a[i]=='0'||a[i]=='1')
            	b[i]=a[i];
			else
				b[i]='9';
		}
		b[i]='\0';
		printf("%s\n",b);
	}
	return 0;
}

