#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iterator>
using namespace std;
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
//const int inf=2000000000;
char fact[102][165],f[162];
int len=1;
void mul(int n)
{
	int i,j,hold=0,sum;
	for(i=0;i<len;i++)
	{
		sum=(f[i]-'0')*n+hold;
		f[i]=sum%10+'0';
		hold=sum/10;
	}
	while(hold)
	{
		f[i++]=hold%10+'0';
		hold/=10;
	}
	f[i]='\0';
	len=i;
	i--;
	for(j=0;j<=i;j++)
		fact[n][j]=f[i-j];
	fact[n][j]='\0';
}
void fac()
{
	fact[0][0]='1';
	fact[1][0]='1';
	strcpy(f,"1");
	for(int i=2;i<101;i++)
		mul(i);
}
int main()
{
	int cas,n;
	fac();
	scanf("%d",&cas);
	while(cas--)
    {
		scanf("%d",&n);
		printf("%s\n",fact[n]);
    }
    return 0;
}
