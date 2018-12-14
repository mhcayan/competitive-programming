#include<stdio.h>
int main()
{
	int t=1,c[12],r[12],s,i;
	while(scanf("%d",&s))
	{
		if(s<0)
			break;
		for(i=0;i<12;i++)
			scanf("%d",&c[i]);
		for(i=0;i<12;i++)
			scanf("%d",&r[i]);
		printf("Case %d:\n",t++);
		for(i=0;i<12;i++)
		{
			if(s<r[i])
				printf("No problem. :(\n");
			else
			{
                printf("No problem! :D\n");
				s-=r[i];
			}
			s+=c[i];		
		}
	}
	return 0;
}
