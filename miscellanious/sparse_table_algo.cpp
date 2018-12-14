#include<stdio.h>
#include<math.h>
int a[10000],m[100000][20];
int min(int x,int y)
{
	return x<y?x:y;
}
void init(int n)
{
	int i,j;
	for(i=0;i<n;i++)
		m[i][0]=i;
	for(j=1;1<<j<=n;j++)
	{
		for(i=0;i+(1<<j)-1<n;i++)
		{
			if(a[m[i][j-1]]<a[m[i+(1<<(j-1))][j-1]])
				m[i][j]=m[i][j-1];
			else
				m[i][j]=m[i+(1<<(j-1))][j-1];
		}
	}
}
int query(int i,int j,int n)
{
	int k;
	k=log(j-i+1)/log(2);
	return min(a[m[i][k]],a[m[j-(1<<k)+1][k]]);
}
int main()
{
	int i,q,j,n;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		init(n);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d %d",&i,&j);
			printf("%d\n",query(i,j,n));
		}
	}
	return 0;
}
