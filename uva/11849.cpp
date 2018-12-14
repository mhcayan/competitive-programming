#include<stdio.h>
long a[1000000],b[1000000];
int main()
{
	int flag;
	long m,n,cd,i,j;
	while(scanf("%ld %ld",&m,&n))
	{
		if(m==0 && n==0)
			break;
		for(i=0;i<m;i++)
			scanf("%ld",&a[i]);
		for(j=0;j<n;j++)
			scanf("%ld",&b[j]);
		flag=1;
		if(a[m-1]<b[0] || b[n-1]<a[0])
		{
			flag=0;
		}
		i=j=cd=0;
		if(flag)
		{
			while(i<m && j<n)
			{
				if(a[i]==b[j])
				{
					cd++;
					i++;j++;
				}
			    else if(a[i]>b[j])
					j++;
			    else
					i++;
			}
		}
		printf("%ld\n",cd);
	}
	return 0;
}

