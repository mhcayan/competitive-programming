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
int main()
{
	long n,i,a[2100],j,b,e,m,value,total;
	while(scanf("%ld",&n) && n)
    {
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		sort(a,a+n);
		total=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				value=a[i]+a[j];
				b=j+1;
				e=n-1;
				while(b<=e)
				{
					m=(b+e)/2;
					if(value>=a[m])
						b=m+1;
					else
						e=m-1;
				}
				if(b<n)
					total+=n-b;
			}
		}
		printf("%ld\n",total);
    }
    return 0;
}
