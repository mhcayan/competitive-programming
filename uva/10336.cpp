#include<stdio.h>
#include<stdlib.h>
int x[4]={-1,0,0,1},y[4]={0,-1,1,0},adj[500][500],vis[500][500],row,col;
typedef struct{
	char name;
	int count;
}tag;
int bfs(int i,int j);
int cmp(const void *a,const void *b)
{
	tag *x=(tag*)a;
	tag *y=(tag*)b;
	if(x->count!=y->count)
		return y->count-x->count;
	else
		return x->name-y->name;
}
int main()
{
	int N,i,j,no,t,loc[200];
	char s[1000];
	tag lan[500];
	scanf("%d",&N);
	for(t=1;t<=N;t++)
	{
		scanf("%d %d",&row,&col);
		no=0;
		for(i='a';i<='z';i++)
			loc[i]=-1;
		for(i=1;i<=row;i++)
		{
			scanf("%s",s);
			for(j=1;j<=col;j++)
			{
				adj[i][j]=s[j-1];
				vis[i][j]=0;
				if(loc[s[j-1]]==-1)
				{
					loc[s[j-1]]=no++;
				}
			}
		}
		for(i=0;i<no;i++)
			lan[i].count=0;
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
			{
				if(vis[i][j]==0)
				{
					vis[i][j]=1;
					bfs(i,j);
					lan[loc[adj[i][j]]].name=adj[i][j];
					lan[loc[adj[i][j]]].count++;
				}
			}
		}
		qsort(lan,no,sizeof(tag),cmp);
		printf("World #%d\n",t);
		for(i=0;i<no;i++)
			printf("%c: %d\n",lan[i].name,lan[i].count);
	}
	return 0;
}
int bfs(int i,int j)
{
	int front,rear,q1[100000],q2[10000],p,q,r,s;
	char c=adj[i][j];
	front=rear=1;
	q1[front]=i;
	q2[front]=j;
    while(front<=rear)
	{
		p=q1[front];
		q=q2[front++];
		for(i=0;i<4;i++)
		{
			r=p+x[i];
			s=q+y[i];
			if(r>0&&s>0&&r<=row&&s<=col)
			{
				if(vis[r][s]==0&&adj[r][s]==c)
				{
					vis[r][s]=1;
					q1[++rear]=r;
					q2[rear]=s;
				}
			}
		}
	}
	return 0;
}

		


