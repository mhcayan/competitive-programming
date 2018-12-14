#include<cstdio>
#include<cmath>
#include<vector>
#define PI acos(-1.0)
using namespace std;
int main()
{
	int cas,t;
	double a,b,c,d,base,h,s;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		base=c-a;
		if(base<0)
			base=-base;
		s=(base+b+d)/2;
		h=2*sqrt(s*(s-base)*(s-b)*(s-d))/base;
		printf("Case %d: %.9lf\n",t,(a+c)*h/2);
	}
	return 0;
}