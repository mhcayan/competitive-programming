#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ch[10000000],a[10000000];
int main()
{
	long i,l;
	while(gets(ch))
	{
		l=strlen(ch);
		for(i=0;i<l;i++)
		{
			a[i]=ch[i]-7;
		    cout<<a[i];
		}
	 cout<<endl;
	}
 return 0;
}