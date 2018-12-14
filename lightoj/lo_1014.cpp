#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	bool flag;
	long cas,t,p,l,m,i,k,a[100000];
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld %ld",&p,&l);
	    p=p-l;
    	m=ceil(sqrt(p));
		k=-1;
		flag=1;
		printf("Case %ld:",t);
	    for(i=1;i<m;i++)
		{
		    if(p%i==0)
			{
			    if(i>l)
				{
				    printf(" %ld",i);
				    a[++k]=p/i;
				}
			    else
				{ 
				    if(p/i>l)
					    a[++k]=p/i;
				    else
					    break;
				}
			}
		}
    	if(m*m==p && m>l)
		{
			flag=0;
	    	printf(" %ld",m);
		}
	    while(k>-1)
		{
			flag=0;
		    printf(" %ld",a[k--]);
		}
		if(flag)
		    printf(" impossible\n");
		else
			printf("\n");
	}

	return 0;
}





