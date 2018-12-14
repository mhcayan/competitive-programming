#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
long find(long n)
{
	long count=0;
	while(n>0)
	{
		n/=5;
		count+=n;
	}
	return count;
}		
int main()
{
	long cas,t,beg,end,mid,i,q,v;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld",&q);
		beg=1;end=400000040;
		while(beg<=end)
		{
			mid=(beg+end)/2;
			v=find(mid);
			if(v==q)
				break;
			if(v<q)
				beg=mid+1;
			else
				end=mid-1;
		}
		if(beg>end)
			printf("Case %ld: impossible\n",t);
		else
		{
			i=mid-1;
			while(find(i)==q)
				i--;
			printf("Case %ld: %lld\n",t,i+1);
		}
	}
	return 0;
}