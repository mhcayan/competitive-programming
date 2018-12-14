#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long p[30]={2,3,5,7,11,13,17,19,23,29,31,37};
typedef struct {
	long num,d;
}tag;
tag node[1005];
int cmp(const void *a,const void *b)
{
	tag *x=(tag *)a;
	tag *y=(tag *)b;
	if(x->d==y->d)
		return y->num-x->num;
	return x->d-y->d;
}
void finddiv()
{
	long k,n,m,div,c,i;
	for(k=1;k<=1000;k++)
	{
		n=k;
		m=sqrt(n);
		div=1;
		for(i=0;p[i]<=m;i++)
		{
			if(n%p[i]==0)
			{
				c=1;
				while(n%p[i]==0)
				{
					c++;
					n/=p[i];
				}
				div*=c;
				m=sqrt(n);
			}
		}
		if(n>1)
			div*=2;
		node[k-1].num=k;
		node[k-1].d=div;
	}
}
int main()
{
	long cas,t,n;
	finddiv();
	qsort(node,1000,sizeof(tag),cmp);
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld",&n);
		printf("Case %ld: %ld\n",t,node[n-1].num);

	}
	return 0;
}