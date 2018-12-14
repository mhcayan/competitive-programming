#include<stdio.h>
#define MAXADJ 200
#define MAXNODE 200
struct adj{
	int a[MAXADJ];
	int size;
};
int main()
{
	int v,e,i,n1,n2,flag,ch,c,t,q,outdeg[1000],indeg[1000];
	scanf("%d",&t);
	for(c=1;c<=t;c++)
	{
		scanf("%d %d",&v,&e);
	    struct adj node[MAXNODE];
		for(i=1;i<=v;i++)
		{
			node[i].size=0;
			outdeg[i]=0;
			indeg[i]=0;
		}
	    for(i=0;i<e;i++)
		{
			scanf("%d %d",&n1,&n2);
		    node[n1].a[node[n1].size++]=n2;
			indeg[n2]++;
			outdeg[n1]++;
		//node[n2].a[node[n1].size++]=n1;
		}
		scanf("%d",&q);
		printf("Case :%d\n",c);
	    while(q--)
		{
			scanf("%d",&ch);
		    if(ch==1)
			{
				scanf("%d %d",&n1,&n2);
			    flag=0;
			    for(i=0;i<node[n2].size;i++)
				{
					if(node[n2].a[i]==n1)
					{
						flag=1;
					    break;
					}
				}
			    if(flag)
					printf("Yes\n");
				else
					printf("No\n");
			}
			else if(ch==2)
			{
				scanf("%d",&n1);
				printf("%d\n",indeg[n1]+outdeg[n1]);
			}
			else if(ch==3)
			{
				flag=0;
				for(i=1;i<=v;i++)
				{
					if(outdeg[i]!=indeg[i])
					{
						flag=1;
						break;
					}
				}
				if(flag)
					printf("No\n");
				else
					printf("Yes\n");
			}
			else if(ch==4)
			{
				scanf("%d",&n1);
				for(i=0;i<node[n1].size-1;i++)
				{
					printf("%d ",node[n1].a[i]);
				}
				if(i<node[n1].size)
					printf("%d",node[n1].a[i]);
				printf("\n");
			}
		}
	
	}
	return 0;
}