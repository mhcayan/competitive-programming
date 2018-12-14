#include<stdio.h>
#include<math.h>
bool flag[10000000];
long long p[666666];
using namespace std;
int sieve()
{
    long long i,c,j;
	p[0]=2;
	c=1;
	for(i=3;i<=3162;i+=2)
	{
		if(flag[i]==0)
		{
			p[c++]=i;
		   for(j=i*i;j<=9999999;j+=i+i)
			flag[j]=1;
        }
	}
	for(;i<=9999999;i+=2)
   {
         if(flag[i]==0)
            p[c++]=i;
   } 
	//printf("%ld\n",c);
	return c;
}
int main()
{
	long long n,i,ans,m,c,l;
	l=sieve();
	while(scanf("%lld",&n) && n!=0)
	{
                           ans=-1;
                           if(n<0)
                           n=-n;

           m=sqrt(n);
           c=0;
           for(i=0;i<l && p[i]<=m;i++)
           {
               if(n%p[i]==0)
               {
                  c++;
                  ans=p[i];
                  while(n%p[i]==0)
                      n=n/p[i];
                  m=sqrt(n);
               }
           }
       if(n>1)
       {
           c++;
           if(n>ans)
              ans=n;
       }
       if(c>1)
          printf("%lld\n",ans);
       else
          printf("-1\n");
       
	}
	return 0;
}
