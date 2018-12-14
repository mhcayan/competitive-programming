#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define eps 1e-11
int main()
{
	bool flag;
	long long cas,t,n,m,b;
	double s,res;
	scanf("%lld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%lld",&n);
		if(n<0)
		{
			n=-n;
			m=sqrt(n+eps);
			s=log(n);
		    flag=1;
	        for(b=2;b<=m;b++)
			{
				//printf("yes\n");
		       res=s/log(b);
		       if((res-floor(res+eps))<eps)
			   {
				  // if(long(res+eps)%2==0)
					//   continue;
				   flag=0;
			       printf("Case %lld: %.0lf\n",t,res);
			       break;
			   }
			}
		    if(flag)
		       printf("Case %lld: 1\n",t);
		}
		else
		{
		    m=sqrt(n);
		    s=log(n);
		    flag=1;
		    for(b=2;b<=m;b++)
			{
			    res=s/log(b);
			    if((res-floor(res+eps))<eps)
				{
				    flag=0;
				    printf("Case %lld: %.0lf\n",t,res);
				   break;
				}
			}
		    if(flag)
			    printf("Case %lld: 1\n",t);
		}
	}
	return 0;
}


