#include<stdio.h>
int main()
{
	int a[100][100],n,stack[100]={0},s,i,v,j,top,status[100]={0};
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	printf("ENTER THE STARTING NODE\n");
	scanf("%d",&s);
	top=0;
	stack[top]=s;
	status[s]=1;
	printf("FOLLOWING NODES ARE VISITABALE FROM %d\n",s);
	while(top>=0)
	{
		v=stack[top];
		top--;
		printf("%d,",v);
		for(i=1;i<=n;i++)
		{
			if(a[v][i]==1 && status[i]==0)
			{
				top++;
				stack[top]=i;
				status[i]=1;
			}
		}
	}
	return 0;
}


		


