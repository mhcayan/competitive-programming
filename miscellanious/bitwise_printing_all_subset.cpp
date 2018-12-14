#include<stdio.h>
#include<string.h>
inline long square(long x)
{
	return x*x;
}
inline long power(long p)
{
	if(p==0)
		return 1;
	else if(p%2==0)
		return square(power(p/2));
	else
		return 2*power(p-1);
}
int main()
{
	char a[100];
	long l,k,i,j;
	while(gets(a))
	{
		l=strlen(a);
		k=power(l);
		for(i=0;i<k;i++)
		{
			for(j=0;j<l;j++)
			{
				if(i & 1<<j)
					printf("%c",a[j]);
			}
			printf("\n");
		}
	}
	return 0;
}