#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int xx[4]={-1,0,1,0},yy[4]={0,1,0,-1};
int main()
{
	int cas,t,c,r,i,j,front,rear,p,q,m,n,s1,s2,q1[500],q2[500],a[22][22];
	char str[50];
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%d %d",&c,&r);
		getchar();
		for(i=0;i<r;i++)
		{
			gets(str);
			for(j=0;str[j];j++)
			{
				if(str[j]=='.')
					a[i][j]=0;
				else if(str[j]=='#')
					a[i][j]=1;
				else
				{
					s1=i;
					s2=j;
				}
			}
		}
		front=rear=1;
		q1[front]=s1;
		q2[front]=s2;
		a[s1][s2]=1;
		while(front<=rear)
		{
			p=q1[front];
			q=q2[front++];
			for(i=0;i<4;i++)
			{
				m=p+xx[i];
				n=q+yy[i];
				if(m>-1 && m<r && n>-1 && n<c)
				{
					if(a[m][n]==0)
					{
						a[m][n]=1;
						q1[++rear]=m;
						q2[rear]=n;
					}
				}
			}
		}
		printf("Case %d: %d\n",t,rear);
	}
	return 0;
}
		