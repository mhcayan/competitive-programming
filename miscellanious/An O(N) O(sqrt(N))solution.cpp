#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;
const int inf=2000000000;
int n,sq,a[10000000],m[100000];
void init()
{
	int i,j,k;
	for(i=0;i<sq;i++)
	{
		k=i*sq;
		loc=k;
		for(j=1;j<sq;j++)
		{
			if(m[loc]>a[k+j])
				loc=k+j;
		}
		m[i]=loc;
	}
	k=i*sq;
	m[i]=inf;
	for(j=k;j<n;j++)
	{
		if(m[i]>a[j])
			m[i]=a[j];
	}
}
int main()
{
	int i;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sq=sqrt(n);
		init();
		for(i=0;i<=sq;i++)
			printf("%d ",m[i]);
		printf("\n");
	}
	return 0;
}

