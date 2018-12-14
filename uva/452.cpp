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
int taken[100],indeg[100],a[100][100],time[100];
int topsort(int n)
{
	int j,k,i=1,max,total=0;
	stack<int>st;
	while(i<n)
	{
		max=-inf;
		for(j=1;j<n;j++)
		{
			if(!taken[j]  && !indeg[j])
			{
				if(time[j]>max)
					max=time[j];
				taken[j]=1;
				i++;
				st.push(j);
			}
		}
		total+=max;
		while(!st.empty())
		{
			j=st.top();
			st.pop();
			for(k=1;k<n;k++)
			{
				if(a[j][k] && !taken[k])
					indeg[k]--;
			}
		}
		printf("%d\n",i);
	}
	return total;
}

int main()
{
	int cas,node,loc[500],i,t;
	char str[500],ch,s[500];
	scanf("%d",&cas);
	getchar();
	while(cas--)
	{
		getchar();
		CLR(a);
		CLR(loc);
		CLR(indeg);
		CLR(taken);
		node=1;
		while(gets(str))
		{
			if(str[0]=='\0')
				break;
			sscanf(str,"%c %d %s",&ch,&t,s);
			if(loc[ch]==0)
				loc[ch]=node++;
			time[loc[ch]]=t;
			for(i=0;s[i];i++)
			{
				if(loc[s[i]]==0)
					loc[s[i]]=node++;
				a[loc[s[i]]][loc[ch]]=1;
				indeg[loc[ch]]++;
			}
			
		}
		printf("%d\n",topsort(node));
	}
    return 0;
}
