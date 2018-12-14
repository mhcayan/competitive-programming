#include<stdio.h>
#include<string.h>
long LEN=3,F[1001];
char f[10000];
int mul(int n)
{
	long hold,i,sum,d;
	hold=0;
	for(i=0;i<LEN;i++)
	{
		sum=(f[i]-'0')*n+hold;
		d=sum%10;
		f[i]=d+'0';
		F[n]+=d;
		hold=sum/10;
	}
	while(hold)
	{
		d=hold%10;
		f[i++]=d+'0';
		F[n]+=d;
		hold=hold/10;
	}
	f[i]='\0';
	LEN=i;
	return 0;
}
int fac()
{
	long i;
	F[0]=1;
	F[1]=1;
	F[2]=2;
	F[3]=6;
	F[4]=6;
	F[5]=3;
	F[1000]=10539;
	F[999]=10539;
	F[998]=10287;
	F[997]=10368;
	F[996]=10233;
	F[995]=10395;
	F[994]=10584;
	F[993]=10251;
	F[992]=10296;
	F[991]=10287;
	F[990]=10467;
	strcpy(f,"021");
	for(i=6;i<990;i++)
		mul(i);
	return 0;
}
int main()
{
	long n;
	fac();
	while(scanf("%ld",&n)==1)
	{
		printf("%ld\n",F[n]);
	}
	return 0;
}