#include<cstdio>
#include<queue>
using namespace std;
typedef struct{
	int x,y;
}node;
int main()
{
	int cas,tc,c,r,i,j,vis[22][22],xx[4]={-1,0,1,0},yy[4]={0,1,0,-1},count;
	char str[30];
	node s,t;
	queue<node>q;
	scanf("%d",&cas);
	for(tc=1;tc<=cas;tc++)
	{
		scanf("%d %d",&c,&r);
	    getchar();
	    for(i=0;i<r;i++)
		{
		    gets(str);
		    for(j=0;str[j];j++)
			{
			    if(str[j]=='.')
				    vis[i][j]=0;
			    else if(str[j]=='#')
				    vis[i][j]=1;
			    else
				    s.x=i,s.y=j;
			}
		}
    	q.push(s);
	    vis[s.x][s.y]=1;
	    count=1;
	    while(!q.empty())
		{
		    s=q.front();
		    q.pop();
		    for(i=0;i<4;i++)
			{
			    t.x=s.x+xx[i];
			    t.y=s.y+yy[i];
			    if(t.x>-1 && t.x<r && t.y>-1 && t.y<c && vis[t.x][t.y]==0)
				{
				    vis[t.x][t.y]=1;
				    q.push(t);
				    count++;
				}
			}
		}
	    printf("Case %d: %d\n",tc,count);
	}
	return 0;
}

