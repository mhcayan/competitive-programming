#include<stdio.h>
#include<string.h>
char a[100],b[100];
int c[100][100];
char p[100][100];

void printlcs(int m,int n);
int main()
{
	int i,j,m,n;
	while(gets(a))
	{
		gets(b);
		m=strlen(a);
		n=strlen(b);
		for(i=0;i<=n;i++)
			c[0][i]=0;
		for(i=0;i<=m;i++)
			c[i][0]=0;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i-1]==b[j-1])
				{
					c[i][j]=c[i-1][j-1]+1;
					p[i][j]='y';
				}
				else if(c[i][j-1]>=c[i-1][j])
				{
					c[i][j]=c[i][j-1];
					p[i][j]='l';
				}
				else
				{
					c[i][j]=c[i-1][j];
					//p[i][j]='u';
				}
			}
		}
		printf("%d\n",c[m][n]);
		printlcs(m,n);
		printf("\n");
	}
	return 0;
}
void printlcs(int i,int j)
{
	if(i==0 || j==0)
	{
		return;
	}
	if(p[i][j]=='y')
	{
		printlcs(i-1,j-1);
		printf("%c",a[i-1]);
	}
	else if(p[i][j]=='u')
		printlcs(i-1,j);
	else
		printlcs(i,j-1);
}
