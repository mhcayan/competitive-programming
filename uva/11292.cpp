#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	long *x=(long*)a;
	long *y=(long*)b;
	return *x-*y;
}
int main()
{
	long n,m,i,j,loc,s,d[30000],h[30000];
	while(scanf("%ld %ld",&n,&m))
	{
		if(m==0 && n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%ld",&d[i]);
		for(i=0;i<m;i++)
			scanf("%ld",&h[i]);
		if(n>m)
			printf("Loowater is doomed!\n");
		else
		{
		    qsort(d,n,sizeof(long),cmp);
		    qsort(h,m,sizeof(long),cmp);
			s=0;
			loc=0;
		    for(i=0;i<n;i++)
			{
				for(j=loc;j<m;j++)
				{
					if(h[j]>=d[i])
					{
						loc=j+1;
						s+=h[j];
						break;
					}
				}
				if(j==m)
					break;
			}
			if(i==n)
				printf("%ld\n",s);
			else
				printf("Loowater is doomed!\n");
		}
	}
	return 0;
}

