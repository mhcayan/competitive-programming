#include<stdio.h>
#include<string.h>
char a[100],b[100],d[100];
int c[100][100],m,n,k;
char p[100][100];
void printlcs(int m,int n);
int lcs();
int main()
{
	int cas,t;
	scanf("%d",&cas);
		getchar();
	for(t=1;t<=cas;t++)
	{
		getchar();
		gets(a);
		gets(b);
		gets(d);
		m=strlen(a);
		n=strlen(b);
		lcs();
	//	printf("%d\n",c[m][n]);
		k=0;
		printlcs(m,n);
		b[k]='\0';
		printf("%s\n",b);
		strcpy(a,d);
		m=strlen(a);
		n=strlen(b);
		lcs();
		
	
	printf("Case %d: %d\n",t,c[m][n]);
	}
	return 0;
}
int lcs()
{
	int i,j;
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
		b[k++]=a[i-1];
	}
	else if(p[i][j]=='u')
		printlcs(i-1,j);
	else
		printlcs(i,j-1);
}
