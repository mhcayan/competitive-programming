#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iterator>
using namespace std;
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
const int inf=2000000000;
int u[600005];
void update(int node,int b,int e,int i,int j)
{
	if(i>e || j<b)
		return;
	else if(i<=b && e<=j)
		u[node]++;
	else
	{
		update(node*2,b,(b+e)/2,i,j);
		update(node*2+1,(b+e)/2+1,e,i,j);
	}
}
int query(int node,int b,int e,int i)
{
	if(i<b || i>e)
		return 0;
	else if(b==e)
		return u[node];
	else
		return u[node]+query(node*2,b,(b+e)/2,i)+query(node*2+1,(b+e)/2+1,e,i);
}
int main()
{
	int cas,t,e,i,j,q;
	char str[30],s[100005],ch;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		scanf("%s",s);
		e=strlen(s);
		CLR(u);
		scanf("%d",&q);
		getchar();
		printf("Case %d:\n",t);
		while(q--)
		{
			gets(str);
			if(str[0]=='Q')
			{
				sscanf(str,"%c %d",&ch,&i);
				if(query(1,1,e,i)%2)
				{
					if(s[i-1]=='1')
					    printf("0\n");
					else
						printf("1\n");
				}
				else
					printf("%c\n",s[i-1]);
			}
			else
			{
				sscanf(str,"%c %d %d",&ch,&i,&j);
				update(1,1,e,i,j);
			}
		}

    }
    return 0;
}
