#include<stdio.h>
#include<string.h>
char c[105][105];
int lcslen(char p[],char q[]);
int main()
{
	int t=1;
	char a[105],b[105];
	while(1)
	{
		gets(a);
		if(a[0]=='#')
			return 0;
		gets(b);
		printf("Case #%d: you can visit at most %d cities.\n",t++,lcslen(a,b));
	}
	return 0;
}
int lcslen(char p[],char q[])
{
	int m,n,i,j;
	m=strlen(p);
	n=strlen(q);
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(i=1;i<=n;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
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

		