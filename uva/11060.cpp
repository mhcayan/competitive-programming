#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<iterator>
using namespace std;
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
const int inf=2000000000;
int a[105][105],indeg[105],taken[105],list[105];
void topsort(int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(!indeg[j] && !taken[j])
			{
				list[i]=j;
				taken[j]=1;
				for(k=0;k<n;k++)
				{
					if(a[j][k] && indeg[k])
						indeg[k]--;
				}
				break;
			}
		}
	}
}
int main()
{
	int n,i,num,n1,n2,m,t=0;
	string s1,s2,str,bev[105];
	map<string,int>name;
    while(scanf("%d\n",&n)==1)
    {
		CLR(a);
		for(i=0;i<n;i++)
		{
			indeg[i]=0;
			taken[i]=0;
		}
		//CLR(indeg);
		//CLR(taken);
		name.clear();
		for(i=0;i<n;i++)
		{
			cin>>str;
			bev[i]=str;
			name[str]=i;
		}
		scanf("%d\n",&m);
		while(m--)
		{
            cin>>s1>>s2;
//			scanf("%s %s\n",s1,s2);
			n1=name[s1];
			n2=name[s2];
			if(!a[n1][n2])
			{
			    a[n1][n2]=1;
			    indeg[n2]++;
            }
		}
		topsort(n);
		printf("Case #%d: Dilbert should drink beverages in this order:",++t);
		for(i=0;i<n;i++)
		{
			cout<<' '<<bev[list[i]];
		}
		printf(".\n\n");
    }
    return 0;
}
