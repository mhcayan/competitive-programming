#include<stdio.h>

int main()
{
	long i,b[40000],count[35000]={0},locp[35000],locn[35000],j=-1,statusp[35000]={0},statusn[35000]={0},n;
	while(scanf("%ld",&n)==1)
	{
		if(n>-1)
		{
			if(statusp[n]==0)
			{
				b[++j]=n;
				locp[n]=j;
				count[j]++;
				statusp[n]=1;
			}
			else
			{
				count[locp[n]]++;
			}
		}
		else
		{
			if(statusn[-n]==0)
			{
				b[++j]=n;
				locn[-n]=j;
				count[j]++;
				statusn[-n]=1;
			}
			else
			{
				count[locn[-n]]++;
			}
		}
	}
	for(i=0;i<=j;i++)
		printf("%ld %ld\n",b[i],count[i]);
	return 0;
}




