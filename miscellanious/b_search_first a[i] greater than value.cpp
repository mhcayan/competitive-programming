//index of first element of a which is>value 
#include<stdio.h>
int main()
{
	int n,i,value,b,e,m,a[100];
	while(scanf("%d",&n)==1)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		while(scanf("%d",&value)==1)
		{
			b=1;
			e=n;
			while(b<=e)  
			{
                 m=(b+e)/2;  
                 if(a[m]>value)//it will be a[m]>=value if index of first element of a which is>=value 
                     e=m-1;
                 else
                     b=m+1;
            }
            if(b>n)
                printf("not found\n");
            else
               printf("index=%d number=%d\n",b,a[b]);
            
		}
	}
	return 0;
}

