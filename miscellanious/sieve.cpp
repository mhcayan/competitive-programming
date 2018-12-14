#include<stdio.h>
#include<math.h>
long flag[20000100],a[20000100];
int main()
{
	long n,m,i,j,c;
	scanf("%ld",&n)==1;
	//{
        a[0]=2;
        c=1;
	    m=sqrt(n);
	    for(i=3;i<=m;i+=2)
	    {
            if(flag[i]==0)
            {
                a[c++]=i;
                for(j=i*i;j<=n;j+=i+i)
                    flag[j]=1;
            }
        }
	    for(;i<=n;i+=2)
		    if(flag[i]==0)
			    a[c++]=i;
	    printf("%ld\n",c);
	    for(i=0;i<c;i++)
	    {
		    printf("%ld,",a[i]);
		    if(i%15==0)
		        printf("\n");
         }
    //}
	return 0;
}


