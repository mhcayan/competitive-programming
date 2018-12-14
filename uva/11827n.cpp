#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int gcd(int,int);
int main()
{
	char s[10000],d[100];
	int n,i,j,k,a[1000],max,l,g;
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
				g=gcd(a[i],a[j]);
				if(g>max)
					max=g;
			}

		}
		printf("%d\n",max);
	}
	return 0;
}
int gcd(int a,int b)
{
	int r;
	r=b%a;
	if(r==0)
		return a;
	return gcd(r,a);
}


				



	