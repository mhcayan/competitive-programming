//run in dev to take input upto EOF

#include<iostream>
using namespace std;
int main()
{
	char *fib[4787],str[1100];
	long l1,l2,l,i,j,k,m,c,s1,s2,sum;
	fib[1]="1";
	fib[2]="1";
	l1=l2=1;
	for(i=3;i<=4786;i++)
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
		l2=c;
	}
	while(cin>>m)
	{
		cout<<fib[m]<<"\n";
	}
	return 0;
}
