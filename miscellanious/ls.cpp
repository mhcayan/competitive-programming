#include<stdio.h>
#include<string.h>
long a[1800][1800],m,n,step;
char b[1800][1800];
long length_lcs(char a[],char b[]);
void print_lcs(char *x,long i,long j);
int main()
{
    long len;
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
	while(strlen(x[i])!=0 && strlen(y[i])!=0)
	{
		len=length_lcs(x[i],y[i]);
        printf("Length of LCS = %ld\n",len);
        printf("LCS is \"");
	    print_lcs(x[i],m,n);
	    printf("\"\n");
		i++;
	}
	printf("Steps=%ld\n",step); 
	return 0;
}
long length_lcs(char x[],char y[])
{
	long i,j;
	m=strlen(x);
	step++;
	n=strlen(y);
	step++;
	for(i=0,step++;i<=m;i++,step++)
	{
		a[i][0]=0;
		step++;
	}
	for(i=0,step++;i<=n;i++,step++)
	{
		a[0][i]=0;
		step++;
	}
	for(i=1,step++;i<=m;i++,step++)
		for(j=1,step++;j<=n;j++,step++)
		{
			if(x[i-1]==y[j-1])
			{
				a[i][j]=a[i-1][j-1]+1;
				b[i][j]='c';
				step+=2;
			}
			else if(a[i-1][j]>=a[i][j-1])
			{
				a[i][j]=a[i-1][j];
				b[i][j]='u';
				step+=2;
			}
			else
			{
				a[i][j]=a[i][j-1];
				b[i][j]='s';
				step+=2;
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
		step++;
		printf("%c",x[i-1]);
	}
	else if(b[i][j]=='u')
	{
		step++;
		print_lcs(x,i-1,j);
	}
	else
	{
		step++;
		print_lcs(x,i,j-1);
	}
}


