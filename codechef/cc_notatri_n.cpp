#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int a[2005],i,n,total,b,e;
	while(scanf("%d",&n) && n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		total=0;
		for(i=n-1;i>1;i--)
		{
			b=0,e=i-1;
			while(b<e)
			{
				if(a[b]+a[e]<a[i])
				{
					total+=e-b;
					b++;
				}
				else
					e--;
			}
		}
		printf("%d\n",total);
	}
	return 0;
}

