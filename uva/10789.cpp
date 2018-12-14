#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int isprime(int);
int cmp(const void *a,const void *b)
{
	int *x=(int *)a;
	int *y=(int *)b;
	return *x-*y;
}
int main()
{
	int c,t,p[500],index,i,flag;
	char s[5000];
	scanf("%d",&c);
	getchar();
	for(t=1;t<=c;t++)
	{	
		int f[500]={0};
		gets(s);
        printf("Case %d: ",t);
		index=0;
		for(i=0;s[i];i++)
		{
			f[s[i]]++;
			if(f[s[i]]==1)
				p[index++]=s[i];
		}
		flag=1;
		qsort(p,index,sizeof(int),cmp);
		for(i=0;i<index;i++)
		{
			if(isprime(f[p[i]]))
			{
				printf("%c",p[i]);
				flag=0;
			}
		}
		if(flag)
			printf("empty\n");
		else
			printf("\n");
	}
	return 0;
}
int isprime(int n)
{
	int m,i;
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else if(n%2==0)
		return 0;
	else
	{
		m=sqrt(n);
		for(i=3;i<=m;i+=2)
		{
			if(n%i==0)
				return 0;
		}
		return 1;
	}

}
