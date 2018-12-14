#include<stdio.h>
int main()
{
	int t,a[1001],s,sum,i,j,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			s=0;
			for(j=0;j<i;j++)
			{
				if(a[i]>=a[j])
					s++;
			}
			sum+=s;
		}
		printf("%d\n",sum);
	}
	return 0;
}