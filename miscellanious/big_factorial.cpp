#include<stdio.h>
#include<string.h>
char fact[1001][10000],f[10000];
long len=1;
int mul(long n)
{
	long i,j,hold,sum;
	hold=0;
	for(i=0;i<len;i++)
	{
		sum=(f[i]-'0')*n+hold;
		f[i]=sum%10+'0';
		hold=sum/10;
	}
	while(hold)
	{
		f[i++]=hold%10+'0';
		hold=hold/10;
	}
	f[i]='\0';
	len=i;
	i--;
	for(j=0;j<=i;j++)
		fact[n][j]=f[i-j];
	fact[n][j]='\0';
	return 0;
}
int fac()
{
	long i;
	fact[0][0]='1';
	strcpy(f,"1");
	for(i=1;i<1001;i++)
		mul(i);
	return 0;
}
int print(int n)
{
	long l;
	l=strlen(fact[n]);
	printf("length=%ld\n",l);
	printf("%s\n",fact[n]);
	return 0;
}
int main()
{
	long n;
	fac();
	while(scanf("%ld",&n)==1)
	{
		print(n);
	}
	return 0;
}