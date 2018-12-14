#include<stdio.h>
int main()
{

	int c,t,count[1000],n,i,j,flag,a[500][500];
	scanf("%d",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%d",&n);
		flag=0;
		for(i=0;i<101;i++)
			count[i]=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				scanf("%ld",&a[i][j]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				count[a[i][j]]++;
				if(count[a[i][j]]>n)
				{
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag)
			printf("Case %ld: no\n",t);
		else
			printf("Case %ld: yes\n",t);
	}
	return 0;
}
