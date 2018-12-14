#include<stdio.h>
#include<time.h>
#define INFINITY 999999
long p[10000],s[1000][1000],m[1000][1000],n,step;
void mcm();
void pop(long,long);
int main()
{
	long i;
	scanf("%ld",&n);
    for(i=1;i<=n;i++)
	{
	   scanf("%ld",&p[i]);
	}
    mcm();
    pop(1,n);
    printf("\n");
	printf("STEPS=%ld\n",step);
    return 0;
}
void mcm()
{
  long i,k,l,j,q;
  for(i=1,step++;i<=n-1;i++,step++)
  {
	  m[i][i]=0;
	  step++;
  }
  n--;
  step++;
  for(l=2,step++;l<=n;l++,step++)
  {
    for(i=1,step++;i<=n-l+1;i++,step++)
	{
	   j=i+l-1;
	   m[i][j]=INFINITY;
	   step+=2;
	   for(k=i,step++;k<j;k++,step++)
	   {
		   q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
		   step++;
		   if(q<m[i][j])
		   {
		     m[i][j]=q;
			 s[i][j]=k;
			 step+=2;
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