#include<stdio.h>
#include<string.h>
int tree[1000];
void insert(int node,int v)
{
	if(tree[node]==-1)
	{
		tree[node]=v;
		return;
	}
	else if(v>=tree[node])
		insert(node*2+1,v);
	else
	    insert(node*2,v);
}
void print(int node)
{
	if(tree[node]==-1)
	    return;
	print(2*node);
	printf("%d\n",tree[node]);
	print(2*node+1);
}
int main()
{
	memset(tree,-1,sizeof(tree));
	int root=1,n,v,i;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&v);
			insert(root,v);
		}
		print(root);
	}
	return 0;
	
}
