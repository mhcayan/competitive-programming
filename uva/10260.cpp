#include<stdio.h>
int main()
{
	char a[1000],b[1000];
	int i,j,flag;
	while(gets(a))
	{
		flag=j=0;
		for(i=0;a[i]!='\0';i++)
		{
			if(flag!=1&&(a[i]=='B'||a[i]=='F'||a[i]=='P'||a[i]=='V'))
			{
				flag=1;
				b[j++]='1';
			}
			else if(flag!=2 && (a[i]=='C'||a[i]=='G'||a[i]=='J'||a[i]=='K'||a[i]=='Q'||a[i]=='S'||a[i]=='X'||a[i]=='Z'))
			{
				flag=2;
				b[j++]='2';
			}
			else if((a[i]=='D'||a[i]=='T')&&flag!=3)
			{
				flag=3;
				b[j++]='3';
			}
			else if(a[i]=='L'&&flag!=4)
			{
				flag=4;
				b[j++]='4';
			}
			else if((a[i]=='M'||a[i]=='N')&&flag!=5)
			{
				b[j++]='5';
				flag=5;
			}
			else if(a[i]=='R'&&flag!=6)
			{
				flag=6;
				b[j++]='6';
			}
			else if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'||a[i]=='H'||a[i]=='W'||a[i]=='Y')
				flag=0;
		}
		b[j]='\0';
		printf("%s\n",b);
	}
	return 0;
}


