#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
#define CLR(a) memset(a,0,sizeof(a))
int main()
{
	char s[100];
	int i,j,n,l;
	while(gets(s))
	{
		l=strlen(s);
		n=pow(2,l);
		for(i=0;i<n;i++)//if s is a set of n element.then this loop will run upto 2^n-1
		{
			for(j=0;j<l;j++)
			{
				if(i & 1<<j)   //if the jth bit is set then print jth element
					printf("%c",s[j]);
			}
			printf("\n");
		}
	}
	return 0;
}