#include<stdio.h>
int ar[1000][1000];
int gcd(int a,int b);
int main()
{
	int n,i,j,k,g,save[1000]={0};
	for(i=499;i>1;i--)
	{
		for(j=i+1;j<501;j++)
		{
			g=gcd(j,i);
			for(k=j;k<501;k++)
				save[k]+=g;
		}
	}
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		printf("%d\n",save[n]+n-1);
	}
	return 0;
}
int gcd(int a,int b)
{
	if(ar[a][b])
		return ar[a][b];
    if(a%b==0)
		return b;
	else
	{
		int i=b;
		int j=a%b;
		return ar[i][j]=gcd(i,j);
	}
}
