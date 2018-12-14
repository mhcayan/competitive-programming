#include<stdio.h>
int main()
{
	unsigned long male[100],total[100],m,f,t,i,n;
	t=1;
    f=1;
	m=0;
   	male[0]=0;
	total[0]=1;
	for(i=1;i<=44;i++)
	{
		f=m+1;
		m=t;
		t=m+f;
		total[i]=t;
		male[i]=m;
	}
	while(scanf("%lu",&n) && n!=-1)
	{	
		printf("%lu %lu\n",male[n],total[n]);
	}
	return 0;
}
