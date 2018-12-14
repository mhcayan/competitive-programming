#include<stdio.h>
long a[2000],l[2000],p[2000];
long lis(long n)
{
	long i,j,mx,index;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[i])
			{
				if(l[j]<=l[i])
				{
					l[j]=l[i]+1;
					p[j]=i;
				}
			}
		}
	}
	mx=l[0];
	index=0;
	for(i=1;i<n;i++)
	{
		if(l[i]>mx)
		{
			mx=l[i];
			index=i;
		}
	}
	return index;
}
int print(long index)
{
	if(p[index]==index)
	{
		printf("%ld ",a[index]);
		return 0;
	}
	print(p[index]);
	printf("%ld ",a[index]);
	return 0;
}
int main()
{
	long n,i,index;
	while(scanf("%ld",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			l[i]=1;
			p[i]=i;
		}
		index=lis(n);
		printf("\nlength of lis=%ld\n",l[index]);
		print(index);
	}
	return 0;
}
