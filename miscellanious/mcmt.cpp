#include<stdio.h>
#include<time.h>
#define INFINITY 999999
long p[10000],s[1000][1000],m[1000][1000],n;
void mcm();
void pop(long,long);
int main()
{
	clock_t s,e;
	long i;
	scanf("%ld",&n);
    for(i=1;i<=n;i++)
	{
	   scanf("%ld",&p[i]);
	}
	s=clock();
    mcm();
	e=clock();
    pop(1,n);
    printf("\n");
	printf("RUN TIME=%ld",(e-s));
    return 0;
}
void mcm()
{
  long i,k,l,j,q;
  for(i=1;i<=n-1;i++)
	  m[i][i]=0;
  n--;
  for(l=2;l<=n;l++)
  {
    for(i=1;i<=n-l+1;i++)
	{
	   j=i+l-1;
	   m[i][j]=INFINITY;
	   for(k=i;k<j;k++)
	   {
		   q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
		   if(q<m[i][j])
		   {
		     m[i][j]=q;
			 s[i][j]=k;
		   }
	   }
	}  
  
  }
  printf("Total multiplication=%ld\n",m[1][n]);
  
}
void pop(long i,long j)
{
   if(i==j)
	   printf("A%ld",i);
   else
   {
	 printf("(");
     pop(i,s[i][j]);
	 printf("*");
	 pop(s[i][j]+1,j);
	 printf(")");
	   
   }
}