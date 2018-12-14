#include<stdio.h>
int main()
{
	long t,total,value[300],m,k,j,v;
	double cent;
	char a[11000],c;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&k);
		getchar();
		for(j=0;j<290;j++)
			value[j]=0;
		for(j=0;j<k;j++)
		{
			scanf("%c %ld",&c,&v);
			value[c]=v;
			getchar();
		}
		scanf("%ld",&m);
		getchar();
		total=0;
		while(m--)
		{
			gets(a);
			for(j=0;a[j];j++)
			{
				if(value[a[j]])
				    total+=value[a[j]];
			}
		}
		cent=(double)total/100;
		printf("%.2lf$\n",cent);
	}
	return 0;
}
				
