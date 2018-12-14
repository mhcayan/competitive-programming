#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int perm(int how);
char a[100],b[100];
int vis[1000],c;
int cmp(const void *a,const void *b)

{
    char *x=(char*)a;
    char *y=(char*)b;
    return *x-*y;
}
int main()
{
	memset(vis,0,sizeof(vis));
	while(gets(a))
	{
		qsort(a,strlen(a),sizeof(char),cmp);
		c=0;
		perm(0);
		printf("total=%d\n",c);
	}
	return 0;
}
int perm(int how)
{
	int i;
	for(i=0;a[i];i++)
	{
		if(a[how]=='\0')
		{
			b[how]='\0';
			printf("%s\n",b);
			c++;
			return 0;
		}
		else
		{
		    if(vis[a[i]]==0)
			{
			
				vis[a[i]]=1;
		        b[how]=a[i];
			    perm(how+1);
			    vis[a[i]]=0;
			}
		} 
	}
	return 0;

}
