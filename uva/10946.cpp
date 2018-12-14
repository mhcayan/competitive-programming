#include<stdio.h>
#include<stdlib.h>
int xx[4]={-1,0,0,1},yy[4]={0,-1,1,0},x,y;
char adj[50][50];
typedef struct{
	char name;
	int size;
}tag;
int bfs(int i,int j);
int cmp(const void *a,const void *b)
{
	tag *x=(tag*)a;
	tag *y=(tag*)b;
	if(x->size!=y->size)
		return y->size-x->size;
	else
		return x->name-y->name;
}
int main()
{
	tag hole[2500];
	int i,j,n,t=1;
	char s[100];
	while(scanf("%d %d",&x,&y))
	{
		if(!x && !y)
			break;
		for(i=1;i<=x;i++)
		{
			scanf("%s",s);
			for(j=1;j<=y;j++)
			{
				adj[i][j]=s[j-1];
			}
		}
		n=0;
		for(i=1;i<=x;i++)
		{
			for(j=1;j<=y;j++)
			{
				if(adj[i][j]!='.')
				{
					hole[n].name=adj[i][j];
					hole[n].size=bfs(i,j);
					n++;
				}
			}
		}
		qsort(hole,n,sizeof(tag),cmp);
		printf("Problem %d:\n",t++);
		for(i=0;i<n;i++)
			printf("%c %d\n",hole[i].name,hole[i].size);
	}
	return 0;
}
int bfs(int i,int j)
{
    char ch=adj[i][j];
	int front,rear,q1[10000],q2[10000],p,q,r,s;
	front=rear=1;
	q1[front]=i;
	q2[front]=j;
	adj[i][j]='.';
	while(front<=rear)
	{
		p=q1[front];
		q=q2[front++];
		for(i=0;i<4;i++)
		{
			r=p+xx[i];
			s=q+yy[i];
			if(r>0&&s>0&&r<=x&&s<=y)
			{
				if(adj[r][s]==ch)
				{
					q1[++rear]=r;
					q2[rear]=s;
					adj[r][s]='.';
				}
			}
		}
		
	}
	return rear;
}


					
