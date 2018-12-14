#include<stdio.h>
#define INFINITY 999999
long p[10000],s[100][100],n,step;
void mcm();
void print(long,long);
int main()
{
	long i;
	scanf("%ld",&n);
    for(i=0;i<n;i++)
	{
	   scanf("%ld ",&p[i]);
	}
    mcm();
    print(1,n);
    printf("\n");
	printf("STEPS=%ld",step);
    return 0;
}
void mcm()
{
  long m[100][100],i,k,l,j,q;
  for(i=1,step++;i<=n;i++,step++)
	  m[i][i]=0;
  for(l=2,step++;l<=n;l++,step++)
  {
    for(i=1,step++;i<=n-l+1;i++,step++)
	{
	   j=i+l-1;
	   m[i][j]=INFINITY;
	   step+=2;
	   for(k=i,step++;k<j;k++,step++)
	   {
		   q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
		   step+=4;
		   if(q<m[i][j])
		   {
		     m[i][j]=q;
			 s[i][j]=k;
			 step+=2;
		   }
	   }
	}  
  
  }
  
}
void print(long i,long j)
{
   if(i==j)
	   printf("A%ld",i);
   else
   {
	 printf("(");
     print(i,s[i][j]);
	 printf("*");
	 print(s[i][j]+1,j);
	 printf(")");
	   
   }
}