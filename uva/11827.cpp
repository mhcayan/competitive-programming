#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[10000],d[100];
	int n,i,j,k,a[1000],max,p,q,r,l;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		gets(s);
		l=strlen(s);
		j=k=0;
		for(i=0;i<=l;i++)
		{
			if(s[i]>='0' && s[i]<='9')
				d[j++]=s[i];
			else
			{
				if(j>0)
				{
				    d[j]='\0'; 	
					j=0;
					a[k++]=atoi(d);
				}
			}
		}
		k--;
		max=1;
	    for(i=0;i<k;i++)
		{
			for(j=i+1;j<=k;j++)
			{   
				p=a[i];
		        q=a[j];
				while(1)
				{
					r=q%p;
					if(r==0)
						break;
					q=p;
					p=r;
				}
				if(p>max)
					max=p;
			}
		}
		printf("%d\n",max);
	}
		return 0;
}


				



	