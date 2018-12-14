#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char ch;
	int count;
}tag;
int cmp(const void *a,const void*b)
{
	tag *x=(tag *)a;
	tag *y=(tag *)b;
	if(x->count==y->count)
		return x->ch-y->ch;
	return y->count-x->count;
}
int main()
{
	char p,a[10000];
	int i,loc[200],no,n;
	tag node[50];
	scanf("%d\n",&n);
	for(p='A';p<='Z';p++)
		loc[p]=-1;
	no=0;
	while(n--)
	{
		gets(a);
		for(i=0;a[i];i++)
		{
			if(a[i]>='a'&&a[i]<='z')
				a[i]-=32;
			if(a[i]>='A'&&a[i]<='Z')
			{
				if(loc[a[i]]==-1)
				{
					node[no].ch=a[i];
					node[no].count=1;
					loc[a[i]]=no;
					no++;
				}
				else
				{
					node[loc[a[i]]].count++;
				}
			}
		}
	}
	qsort(node,no,sizeof(tag),cmp);
	for(i=0;i<no;i++)
		printf("%c %d\n",node[i].ch,node[i].count);
	return 0;
}
