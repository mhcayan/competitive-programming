#include<stdio.h>
#include<string.h>
char str[30]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",a[100],p[100];
bool vis[100];
int N,K,count;
int perm(int how)
{
	int i;
	if(count==K)
		return 0;
	if(how==N)
	{
		count++;
		printf("%s\n",p);
		return 0;
	}
	for(i=0;i<N;i++)
	{
		if(vis[i]==0)
		{
			p[how]=a[i];
			vis[i]=1;
			perm(how+1);
			vis[i]=0;
		}
	}
	return 0;
}
int main()
{
	int t,i,cas,n;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
	{
		count =0;
		scanf("%d %d",&n,&K);
		for(i=0;i<n;i++)
			a[i]=str[i];
		a[i]='\0';
		p[i]='\0';
		N=i;
		printf("Case %ld:\n",t);
		perm(0);
	}
	return 0;
}