#include<stdio.h>
int main()
{
	int a[1000],n,i,j,c,t=1,status[30000],flag;
	for(i=0;i<20001;i++)
		status[i]=0;
	while(scanf("%d",&n)==1)
	{
		flag=0;
		scanf("%d",&a[0]);
		if(a[0]<1)
			flag=1;
		for(i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<a[i-1])
				flag=1;
		}
		if(!flag)
		{
		    for(i=0;i<n;i++)
			{
			    for(j=i;j<n;j++)
				{
				    c=a[i]+a[j];
				    if(status[c]==t)
					{
					    flag=1;
				 	    break;
					}
				    else
					    status[c]=t;
				}
			    if(flag)
				    break;
			}
		}
		if(flag)
			printf("Case #%d: It is not a B2-Sequence.\n\n",t++);
		else
			printf("Case #%d: It is a B2-Sequence.\n\n",t++);
	}
	return 0;
}
