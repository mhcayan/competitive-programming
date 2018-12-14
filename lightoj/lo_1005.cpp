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
const int inf=2000000000;
long fact[22];
long gcd(long a,long b)
{
	long r;
	while(1)
    {
        r=b%a;
        if(r==0)
            break;
        b=a;
        a=r;
    }
	return a;
}
void divbygcd(long &x,long &y)
{
	long g=gcd(x,y);
	x/=g;
	y/=g;
}
long nck(long n,long k)
{
	long num=1,den=1,tomul,todiv,i;
	if(k>n-k)
		k=n-k;
	for(i=k;i;i--)
	{
		tomul=n-k+i;
		todiv=i;
		divbygcd(tomul,todiv);
		divbygcd(tomul,den);
		divbygcd(num,todiv);
		num*=tomul;
		den*=todiv;
	}
	return num/den;
}

int main()
{
	long cas,t,n,k,i,res;
	fact[0]=fact[1]=1;
	for(i=2;i<20;i++)
		fact[i]=i*fact[i-1];
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
    {
		scanf("%ld %ld",&n,&k);
		if(k>n)
			printf("Case %ld: 0\n",t);
		else if(k==1)
			printf("Case %ld: %ld\n",t,n*n);
		else if(k==n || k==0)
			printf("Case %ld: %ld\n",t,fact[n]);
		else
		{
		    res=1;
			for(i=0;i<k;i++)
				res*=(n-i);
			printf("Case %ld: %ld\n",t,res*nck(n,k));
		}

    }
    return 0;
}
