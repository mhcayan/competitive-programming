#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
	char *fib[5001],str[1000],a[1000],b[1000];
	long l1,l2,l,i,j,k,m,c,sum,s1,s2,count;
	fib[1]="1";
	fib[2]="2";
	l1=1;l2=1;
	for(i=3;i<=5000;i++)
	{
		l=l1>=l2?l1:l2;
		c=0;
		for(j=l1-1,k=l2-1,m=0;m<l;j--,k--,m++)
		{
			if(j<0)
				fib[i-2][j]='0';
			s1=fib[i-2][j]-'0';
			if(k<0)
				fib[i-1][k]='0';
			s2=fib[i-1][k]-'0';
			sum=s1+s2+c;
			if(sum>9)
			{
				str[m]=sum-10+'0';
				c=1;
			}
			else
			{
				str[m]=sum+'0';
				c=0;
			}
		}
		if(c)
			str[m]=c+'0';
		else
			m--;
		fib[i]=new char[m+2];
		for(c=0;c<=m;c++)
			fib[i][c]=str[m-c];
		fib[i][c]='\0';
		l1=l2;
		l2=strlen(fib[i]);
	}
	/*while(scanf("%s %s",a,b))
	{
		if(strcmp(a,"0")==0 && strcmp(b,"0")==0)
			break;
		for(i=0;;i++)
		{
			if(strcmp(a,fib[i])>=0)
				break;
		}
		count=0;
		for(j=i;;j++)
		{
			if(strcmp(b,fib[i])<=0)
				count++;
			else
				break;
		}
		printf("%ld\n",count);
	}*/
	while(scanf("%ld",&c)==1)
	  printf("%s\n",fib[c]);
	return 0;
}

