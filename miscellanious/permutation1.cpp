#include<stdio.h>
#include<string.h>
char a[100];
long p;
void exchange(int i,int n);
void perm(int n);
int main()
{
	gets(a);
	for(int j=0;j<3;j++)
			printf("%c",a[j]);
    printf("\n");
	perm(strlen(a));
	printf("Total permutation=%ld\n",p);
	return 0;
}
void perm(int n)
{
	if(n==0)
	{
		for(int j=0;j<3;j++)
			printf("%c",a[j]);
		p++;
		printf("\n");
	}
	for(int i=0;i<=n;i++)
	{
		exchange(i,n);
		perm(n-1);
		exchange(i,n);
	}
}
void exchange(int i,int n)
{
	char ch=a[i];
	a[i]=a[n];
	a[n]=ch;
}


