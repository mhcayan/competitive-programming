#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[100],b[100];
	long n,i,j,op,l,t;
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		gets(a);
		op=0;
		while(1)
		{
			l=strlen(a)-1;
			for(i=0;i<=l;i++)
				b[i]=a[l-i];
			b[i]='\0';
			if(!strcmp(a,b))
				break;
			else
			{
				j=-1;
				n=atol(a)+atol(b);
				op++;
				while(n)
				{
					b[++j]=n%10+'0';
					n=n/10;
				}
				for(i=0;i<=j;i++)
					a[i]=b[j-i];
				a[i]='\0';
			}
		}
		printf("%ld %s\n",op,a);
	}
	return 0;
}
