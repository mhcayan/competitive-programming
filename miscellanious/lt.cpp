#include<stdio.h>
#include<string.h>
#include<time.h>
long a[1800][1800],m,n;
char b[1800][1800];
long length_lcs(char a[],char b[]);
void print_lcs(char *x,long i,long j);
int main()
{
    long len;
	clock_t s,e;
	char x[1800][100],y[1800][100];
    printf("______Enter two null string to terminate______\n");
    for(long i=0; ;i++)		
	{
		printf("Enter string 1:\n");
		gets(x[i]);
		printf("Enter string 2:\n");			
		gets(y[i]);
		if(strlen(x[i])==0 && strlen(y[i])==0)
			break;
	}
	i=0;
	s=clock();
	while(strlen(x[i])!=0 && strlen(y[i])!=0)
	{
		len=length_lcs(x[i],y[i]);
      //  printf("Length of LCS = %ld\n",len);
      //  printf("LCS is \"");
	    print_lcs(x[i],m,n);
	  //  printf("\"\n");
		i++;
	}
	e=clock();
	printf("Run time=%ld\n",(e-s)); 
	return 0;
}
long length_lcs(char x[],char y[])
{
	long i,j;
	m=strlen(x);
	n=strlen(y);
	for(i=0;i<=m;i++)
		a[i][0]=0;
	for(i=0;i<=n;i++)
		a[0][i]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				a[i][j]=a[i-1][j-1]+1;
				b[i][j]='c';
			}
			else if(a[i-1][j]>=a[i][j-1])
			{
				a[i][j]=a[i-1][j];
				b[i][j]='u';
			}
			else
			{
				a[i][j]=a[i][j-1];
				b[i][j]='s';
			}
		}
		return a[i-1][j-1];
}
void print_lcs(char x[1000],long i,long j)
{
	if(i==0 || j==0)
		return;
	if(b[i][j]=='c')
	{
		print_lcs(x,i-1,j-1);
		//printf("%c",x[i-1]);
	}
	else if(b[i][j]=='u')
		print_lcs(x,i-1,j);
	else
		print_lcs(x,i,j-1);
}


