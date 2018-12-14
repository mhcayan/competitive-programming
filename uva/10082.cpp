#include<stdio.h>
int main()
{
	char a[1000],b[1000];
	int i;
	while(gets(a))
	{
		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]==' ')
				b[i]=' ';
			else if(a[i]=='W')
				b[i]='Q';
			else if(a[i]=='E')
				b[i]='W';
	        else if(a[i]=='R')
				b[i]='E';
        	else if(a[i]=='T')
				b[i]='R';
        	else if(a[i]=='Y')
				b[i]='T';
	        else if(a[i]=='U')
				b[i]='Y';
	        else if(a[i]=='I')
				b[i]='U';
         	else if(a[i]=='O')
				b[i]='I';
	        else if(a[i]=='P')
				b[i]='O';
	        else if(a[i]=='[')
				b[i]='P';
        	else if(a[i]=='S')
				b[i]='A';
	        else if(a[i]=='D')
				b[i]='S';
            else if(a[i]=='F')
				b[i]='D';
	        else if(a[i]=='G')
				b[i]='F';
	        else if(a[i]=='H')
				b[i]='G';
            else if(a[i]=='J')
				b[i]='H';
	        else if(a[i]=='K')
				b[i]='J';
	        else if(a[i]=='L')
				b[i]='K';
	        else if(a[i]==';')
				b[i]='L';
	        else if(a[i]=='X')
				b[i]='Z';
	        else if(a[i]=='C')
				b[i]='X';
	        else if(a[i]=='V')
				b[i]='C';
            else if(a[i]=='B')
				b[i]='V';
	        else if(a[i]=='N')
				b[i]='B';
	        else if(a[i]=='M')
				b[i]='N';
	        else if(a[i]==',')
				b[i]='M';
	        else if(a[i]=='.')
				b[i]=',';
	        else if(a[i]=='/')
				b[i]='.';
	        else if(a[i]=='1')
				b[i]='`';
	        else if(a[i]=='2')
				b[i]='1';
	        else if(a[i]=='3')
				b[i]='2';
	        else if(a[i]=='4')
				b[i]='3';
            else if(a[i]=='5')
				b[i]='4';
	        else if(a[i]=='6')
				b[i]='5';
	        else if(a[i]=='7')
				b[i]='6';
	        else if(a[i]=='8')
				b[i]='7';
            else if(a[i]=='9')
				b[i]='8';
	        else if(a[i]=='0')
				b[i]='9';
	        else if(a[i]=='-')
				b[i]='0';
	        else if(a[i]=='=')
				b[i]='-';
            else if(a[i]==']')
				b[i]='[';
	        else if(a[i]=='\'')
				b[i]=';';
	        else if(a[i]=='\\')
				b[i]='\'';
	        else if(a[i]=='/')
				b[i]='.';
		}
		b[i]='\0';
		printf("%s\n",b);
	}
	return 0;
}