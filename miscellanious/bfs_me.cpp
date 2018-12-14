#include<stdio.h>
struct tag
{
	int a[100];
	int size;
	int status;
	int parent;
	int dis;
}node[100];
int main()
{
	int indeg[100],outdeg[100],f1,l,flag;
	int v,e,i,front,rear,p,q,n,queue[1000],s,d;
	scanf("%ld %ld",&v,&e);
	for(i=1;i<=v;i++)
	{
		indeg[i]=0;
		outdeg[i]=0;
		node[i].size=0;
		node[i].status=1;
		node[i].dis=99999;
		node[i].parent=0;
	}
	for(i=0;i<e;i++)
	{
		scanf("%ld %ld",&p,&q);
		node[p].a[node[p].size++]=q;
		indeg[q]++;
		outdeg[p]++;
		node[q].parent=p;
	}
	scanf("%ld %ld %ld",&s,&d,&l);
	front=rear=1;
	queue[rear]=s;
	node[s].status=2;
	node[s].dis=0;
	flag=0;
	while(front<=rear)
	{
		n=queue[front];
		front++;
		for(i=0;i<node[n].size;i++)
		{
			if(node[node[n].a[i]].status==1)
			{
				rear++;
				queue[rear]=node[n].a[i];
				node[node[n].a[i]].status=2;
				node[node[n].a[i]].parent=n;
				node[node[n].a[i]].dis=1+node[n].dis;
				if(queue[rear]==d)
				{
					if(node[d].dis==l)
					{
					    flag=1;		
					    break;
					}
					else
					{
						rear--;
						node[d].status=1;
					}
				}

			}
		}
		if(flag)
			break;
	}
	if(flag)
		printf("yes");
	else
		printf("no");
	//if(node[d].dis>=99999)
	//	printf("\n");
    //else
	//	printf("\n%d\n",node[d].dis);
//	for(i=1;i<=rear;i++)
//		printf("%ld ",queue[i]);
/*	f1=1;
	for(i=1;i<=v;i++)
	{
		if(indeg[i]!=outdeg[i])
		{
			f1=0;
			break;
		}
	}
	if(f1==1 && rear==v)
		printf("yes\n");
	else
		printf("no\n");*/
	return 0;
}

