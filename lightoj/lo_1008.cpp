#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define eps 1e-11
int main()
{
	long cas,t,s,m,n,x,y;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld",&s);
		m=ceil(sqrt(s));
		n=m*m;
		if(m%2==0)
		{
			if(n-s<m)
				x=m,y=n-s+1;
			else
				x=s-(m-1)*(m-1),y=m;
		}
		else
		{
			if(n-s<m)
				x=n-s+1,y=m;
			else
				x=m,y=s-(m-1)*(m-1);
		}
		printf("Case %ld: %ld %ld\n",t,x,y);
	}
	return 0;
}
