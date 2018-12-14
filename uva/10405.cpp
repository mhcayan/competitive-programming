#include<stdio.h>
#include<string.h>
char c[1001][1001];
int lenlcs(char p[],char q[]);
int main()
{
	char a[1000],b[1000];
	while(gets(a))
	{
		gets(b);
		printf("%d\n",lenlcs(a,b));
	}
	return 0;
}
int lenlcs(char p[],char q[])
{
	int m,n,i,j;
	m=strlen(p);
	n=strlen(q);
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(j=1;j<=n;j++)
		c[0][j]=0;
	for(i=1;i<=m;i++)
		for(j=0;j<=n;j++)
		{
			if(p[i-1]==q[j-1])
				c[i][j]=c[i-1][j-1]+1;
			else if(c[i][j-1]>=c[i-1][j])
				c[i][j]=c[i][j-1];
			else
				c[i][j]=c[i-1][j];
		}
		return c[m][n];
}

		