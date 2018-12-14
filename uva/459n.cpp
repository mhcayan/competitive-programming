#include<stdio.h>
int bfs(int n);
int vis[200];
struct{
	int a[5000],size;
}node[30];
int main()
{
	int t,i,maxl,count,no,loc[1000],p,q;
	char mch,ch,s[100];
	scanf("%d",&t);
	while(t--)
	{
		while(1)
		{
		    scanf("%c",&mch);
			if(mch>='A' && mch<='Z')
				break;
		}
		getchar();
		maxl=mch-'A';
		for(ch='A';ch<=mch;ch++)
			loc[ch]=-1;
		for(i=0;i<=maxl;i++)
		{
			vis[i]=0;
			node[i].size=0;
		}
		loc[mch]=0;
		no=1;
		while(gets(s))
		{
			if(s[0]=='\0')
				break;
			ch=s[0];
			if(loc[ch]==-1)
				loc[ch]=no++;
			p=loc[ch];
			ch=s[1];
			if(loc[ch]==-1)
				loc[ch]=no++;
			q=loc[ch];
			node[p].a[node[p].size++]=q;	
			node[q].a[node[q].size++]=p;
		}
		count=0;
		for(i=0;i<no;i++)
		{
			if(vis[i]==0)
			{
				count++;
				bfs(i);
			}
		}
		printf("%d\n",count);
		if(t)
			printf("\n");
	}
	return 0;
}
int bfs(int n)
{
	int q[100000],front,rear,i,m;
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




