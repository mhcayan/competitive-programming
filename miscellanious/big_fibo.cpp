#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	long n,l1,l2,l,i,j,k,m,ans,c,s1,s2,p;
	char *fib[5001],str[10000];
	fib[0]="0";
	fib[1]="1";
	l1=strlen(fib[0]);
	l2=strlen(fib[1]);
	for(i=2;i<=5000;i++)
	{
		if(l1>=l2)
			l=l1;
		else
			l=l2;
		c=0;
		for(j=l1-1,k=l2-1,m=0;m<l;j--,k--,m++)
		{
			if(j<0)
				fib[i-2][j]='0';
			s1=fib[i-2][j]-'0';
			if(k<0)
				fib[i-1][k]='0';
			s2=fib[i-1][k]-'0';
			ans=s1+s2+c;
			if(ans>9)
			{
				str[m]=ans-10+'0';
				c=1;
			}
			else
			{
				str[m]=ans+'0';
				c=0;
			}
		}
		if(c)
			str[m++]=c+'0';
		str[m]='\0';
		fib[i]=new char[m+1];
		m--;
		for(p=0;p<=m;p++)
			fib[i][p]=str[m-p];
		fib[i][p]='\0';
		l1=l2;
		l2=p;
	}
	while(cin>>n)
	{
		cout<<fib[n]<<'\n'<<strlen(fib[n]);
	}
	return 0;
}
