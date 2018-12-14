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
#include<set>
using namespace std;
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define ff first
#define ss second
#define pii pair<int,int>
#define psi pair<string,int>
#define eps 1e-11
#define mod 100000007

#define sd(a) scanf("%d",&a)
#define sd2(a) scanf("%d %d",&a,&b)
#define slf(a) scanf("%lf",&a)
const int inf=2000000000;
int main()
{
	int tc,n,m,d,a[20],i;
	scanf("%d",&tc);
	while(tc--)
    {
		scanf("%d",&n);
		CLR(a);
		while(n)
		{
			m=n--;
			while(m)
			{
				d=m%10;
				m=m/10;
				a[d]++;
			}
		}
		for(i=0;i<9;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[9]);
    }
    return 0;
}
