#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const long inf=200000000;
int main()
{
	//printf("%ld\n",inf);
	long cas,t,maxx1,maxy1,maxz1,minx2,miny2,minz2,x1,x2,y1,y2,z1,z2,n;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		maxx1=maxy1=maxz1=-inf;
		minx2=miny2=minz2=inf;
		scanf("%ld",&n);
		while(n--)
		{
			scanf("%ld %ld %ld %ld %ld %ld",&x1,&y1,&z1,&x2,&y2,&z2);
		    if(x1>maxx1)
			    maxx1=x1;
		    if(x2<minx2)
			    minx2=x2;
		    if(y1>maxy1)
			    maxy1=y1;
		    if(y2<miny2)
			    miny2=y2;
		    if(z1>maxz1)
			    maxz1=z1;
		    if(z2<minz2)
			    minz2=z2;
		}
		x1=minx2-maxx1;
		y1=miny2-maxy1;
		z1=minz2-maxz1;
		if(x1<=0 || y1<=0 || z1<=0)
			printf("Case %ld: 0\n",t);
		else
			printf("Case %ld: %ld\n",t,x1*y1*z1);
	}
	return 0;
}
