#include<stdio.h>
int main()
{
	int a[11],t,n,i=1,j;
	scanf("%d",&t);
	while(i<=t)
	{
		scanf("%d",&n);
		j=1;
		while(j<=n)
		{
			scanf("%d",&a[j]);
			j++;
		}
		j=j/2;
		printf("Case %d: %d\n",i,a[j]);
		i++;
	}
	return 0;
}
	
