#include<stdio.h>
#include<string.h>
char f[10000];
long fr[500][10];
long len=1;
int mul(long n)
{
	long i,hold,sum,d;
	hold=0;
	for(i=0;i<len;i++)
	{
		sum=(f[i]-'0')*n+hold;
		d=sum%10;
		fr[n][d]++;
		f[i]=d+'0';
		hold=sum/10;
	}
	while(hold)
	{
        d=hold%10;
        fr[n][d]++;
		f[i++]=d+'0';
		hold=hold/10;
	}
	f[i]='\0';
	len=i;
	return 0;
}
int fac()
{
	long i;
	fr[1][1]=1;
	fr[2][2]=1;
	fr[3][6]=1;
	strcpy(f,"6");
	for(i=4;i<367;i++)
		mul(i);
	return 0;
}
int main()
{
	long n,i;
	fac();
	while(scanf("%ld",&n) && n)
	{
		printf("%ld! --\n",n);
		for(i=0;i<5;i++)
			printf("   (%ld)%5d     ",i,fr[n][i]);
		printf("\n");
		for(;i<10;i++)
			printf("   (%ld)%5d     ",i,fr[n][i]);
		printf("\n");
		//printf("   (0)    %ld    (1)    %ld    (2)    %ld    (3)    %ld    (4)    %ld\n",fr[n][0],fr[n][1],fr[n][2],fr[n][3],fr[n][4]);
		//printf("   (5)    %ld    (6)    %ld    (7)    %ld    (8)    %ld    (9)    %ld\n",fr[n][5],fr[n][6],fr[n][7],fr[n][8],fr[n][9]);
	}
	return 0;
}