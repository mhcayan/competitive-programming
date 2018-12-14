#include<stdio.h>
int main()
{
	long i,m=0,a[40000], b[40000],count[35000]={0},locp[35000],locn[35000],j=-1,statusp[35000]={0},statusn[35000]={0},n;
	while(scanf("%ld",&n)==1)
	{
		a[m++]=n;
	}
	for(i=0;i<m;i++)
	{
		if(a[i]>-1)
		{
			if(statusp[a[i]]==0)
			{
				b[++j]=a[i];
				locp[a[i]]=j;
				count[j]++;
				statusp[a[i]]=1;
			}
			else
			{
				count[locp[a[i]]]++;
			}
		}
		else
		{
			if(statusn[-a[i]]==0)
			{
				b[++j]=a[i];
				locn[-a[i]]=j;
				count[j]++;
				statusn[-a[i]]=1;
			}
			else
			{
				count[locn[-a[i]]]++;
			}
		}
	}
	for(i=0;i<=j;i++)
		printf("%ld %ld\n",b[i],count[i]);
	return 0;
}




