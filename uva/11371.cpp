#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
	char *x=(char *)a;
	char *y=(char *)b;
	return *x-*y;
}
int main()
{
	char a[100],b[100],t;
	long l,i,res;
	while(gets(a))
	{
		l=strlen(a);
		qsort(a,l,sizeof(char),cmp);
		l--;
		for(i=0;i<=l;i++)
			b[i]=a[l-i];
		b[i]='\0';
		if(a[0]=='0')
		{
			for(i=1;a[i]=='0';i++);
			t=a[0];
			a[0]=a[i];
			a[i]=t;
		}
		res=atol(b)-atol(a);
		printf("%s - %s = %ld = 9 * %ld\n",b,a,res,res/9);
	}
	return 0;
}


