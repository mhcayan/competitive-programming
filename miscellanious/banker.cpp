#include<stdio.h>
typedef struct{
	int a,b,c;
}process;
process al[100],max[100],av,work,need[100];
int vis[100],n,i,size,seq[100];
int main()
{
	scanf("%d",&n);
	printf("allocation\n");
	for(i=0;i<n;i++)
		scanf("%d %d %d",&al[i].a,&al[i].b,&al[i].c);
	printf("max\n");
	for(i=0;i<n;i++)
		scanf("%d %d %d",&max[i].a,&max[i].b,&max[i].c);
	printf("available:\n");
	scanf("%d %d %d",&av.a,&av.b,&av.c);
	for(i=0;i<n;i++)
	{
		need[i].a=max[i].a-al[i].a;
		need[i].b=max[i].b-al[i].b;
		need[i].c=max[i].c-al[i].c;
	}
	work.a=av.a,work.b=av.b,work.c=av.c;
	//printf("%d %d %d\n",need[0].a,need[0].b,need[0].c);
	while(1)
	{
		for(i=0;i<n;i++)
		{
			if(vis[i]==0 && need[i].a<=work.a && need[i].b<=work.b && need[i].c<=work.c)
			{
				vis[i]=1;
				seq[size++]=i;
				work.a+=al[i].a;
				work.b+=al[i].b;
				work.c+=al[i].c;
				//printf("%d\n",i);
				//printf("%d %d %d\n",work.a,work.b,work.c);
				break;
			}
		}
		if(size==n || i==n)
			break;
	}
	if(size==n)
	{
		for(i=0;i<n;i++)
			printf("%d\n",seq[i]);
	}
	else
		printf("no safe sequence\n");
	return 0;
}


