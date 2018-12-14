#include<stdio.h>
int main()
{
	long count,i,v[200];
	double sum;
	char s[10000];
	v['W']=1;v['H']=2;v['Q']=4;v['E']=8;v['S']=16;v['T']=32;v['X']=64;
	while(scanf("%s",s))
	{
		if(s[0]=='*')
			break;
		sum=0;
		count=0;
		for(i=0;s[i];i++)
		{
			if(s[i]!='/')
			{
				sum+=(double)1/v[s[i]];
			}
			else
			{
				if(sum==1)
					count++;
				sum=0;
			}
		}
		printf("%ld\n",count);
	}
	return 0;
}