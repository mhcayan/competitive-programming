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
int main()
{
	char ch;
	int cas,t,i,n,q,id;
	map<int,int>m;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		scanf("%d %d",&n,&q);
		for(i=0;i<n;i++)
			scanf("%d",&m[i]);
		printf("Case %d:\n",t);
		while(q--)
		{
			scanf("%c %d",&ch,&id);
			if(ch=='a')
				m[m.size()]=id;
			else
			{
				if(id>m.size()+1)
					printf("none\n");
				else
					printf("%d\n",m[id-1]);
			}
		}
    }
    return 0;
}
