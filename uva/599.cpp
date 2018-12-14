#include<stdio.h>
#include<string.h>
int bfs(int);
int vis[200];
struct{
	int a[100],size;
}node[100];
int main()
{
	char p,q,s[1000],ch;
	int t,loc[2000],l,i,acorn,tree,no,m,n;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		no=0;
		for(i=0;i<30;i++)
		{
			vis[i]=0;
			node[i].size=0;
		}
		for(ch='A';ch<='Z';ch++)
		{
			loc[ch]=-1;
		}
		while(gets(s))
		{
			if(s[0]=='*')
				break;
			for(i=0;;i++)
			{
				if(s[i]>='A'&&s[i]<='Z')
				{
					p=s[i];
					break;
				}
			}
			for(i++;;i++)
			{
				if(s[i]>='A' && s[i]<='Z')
				{
					q=s[i];
					break;
				}
			}
			if(loc[p]==-1)
				loc[p]=no++;
			if(loc[q]=-1)
				loc[q]=no++;
			m=loc[p];
			n=loc[q];
			node[m].a[node[m].size++]=n;
			node[n].a[node[n].size++]=m;
		}
		gets(s);
		acorn=tree=0;
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]>='A' && s[i]<='Z')
			{
			    n=loc[s[i]];
			    if(n==-1)
				    acorn++;
			    else if(vis[n]==0)
				{
				    tree++;
				    bfs(n);
				}
			}
		}
        printf("There are %d tree(s) and %d acorn(s).\n",tree,acorn);
	}
	return 0;
}
int bfs(int n)
{
	int q[50000],front,rear,i,m;
	vis[n]=1;
	front=rear=1;
	q[front]=n;
	while(front<=rear)
	{
		n=q[front++];
		for(i=0;i<node[n].size;i++)
		{
			m=node[n].a[i];
			if(vis[m]==0)
			{
				vis[m]=1;
				q[++rear]=m;
			}
		}
	}
	return 0;
}



