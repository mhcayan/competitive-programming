#include<stdio.h>
int main()
{
	int t,i,j,s;
	char a[101];
	scanf("%d",&t);
	getchar();
	for(i=1;i<=t;i++)
	{
		gets(a);
		s=0;
		for(j=0;a[j]!='\0';j++)
		{
			if(a[j]=='a'||a[j]=='d'||a[j]=='g'||a[j]=='j'||a[j]=='m'||a[j]=='p'||a[j]=='t'||a[j]=='w'||a[j]==' ')
				s++;
            else if(a[j]=='b'||a[j]=='e'||a[j]=='h'||a[j]=='k'||a[j]=='n'||a[j]=='q'||a[j]=='u'||a[j]=='x')
				s+=2;
			else if(a[j]=='c'||a[j]=='f'||a[j]=='i'||a[j]=='l'||a[j]=='o'||a[j]=='r'||a[j]=='v'||a[j]=='y')
				s+=3;
            else
			    s+=4;
		}
		printf("Case #%d: %d\n",i,s);
	}
	return 0;   
}
