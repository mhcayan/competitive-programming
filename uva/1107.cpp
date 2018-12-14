#include<stdio.h>
int main()
{
	int a,b,c,t,x1,x2,y1,y2,cow;
	scanf("%d",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&cow);
		printf("Case %d:\n",t);
		while(cow--)
		{
			scanf("%d %d",&a,&b);
			if(a>x1 && a<x2 && b>y1 && b<y2)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}
