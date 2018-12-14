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
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
int xx[]={0,1,2,0,1,2},yy[]={1,1,1,-1,-1,-1};
int dis[26][26][26];
int bfs(string st,string en)
{
	if(dis[st[0]][st[1]][st[2]] || dis[en[0]][en[1]][en[2]])
		return -1;
	if(st==en)
		return 0;
	dis[st[0]][st[1]][st[2]]=1;
	string u,v;
	queue<string>q;
	q.push(st);
	u="abc";v="abc";
	int i;
	while(!q.empty())
	{
		u=q.front();
		q.pop();	
		for(i=0;i<6;i++)
		{
			v[0]=u[0],v[1]=u[1],v[2]=u[2];
			v[xx[i]]=u[xx[i]]+yy[i];
			if(v[xx[i]]<0)
				v[xx[i]]=25;
			else if(v[xx[i]]>25)
				v[xx[i]]=0;
			if(!dis[v[0]][v[1]][v[2]])
			{
				dis[v[0]][v[1]][v[2]]=1+dis[u[0]][u[1]][u[2]];
				if(v==en)
					return dis[v[0]][v[1]][v[2]]-1;
				q.push(v);
			
			}
		}
	}
	return -1;
				
}
int main()
{
	int cas,tc,i,j,k,l1,l2,l3,n,ii;
	string a,b,c,st,en;
	scanf("%d\n",&cas);
	for(tc=1;tc<=cas;tc++)
    {
		CLR(dis);
		cin>>st;
		cin>>en;
		st[0]=st[0]-'a';
		st[1]=st[1]-'a';
		st[2]=st[2]-'a';
		en[0]=en[0]-'a';
		en[1]=en[1]-'a';
		en[2]=en[2]-'a';	
		scanf("%d",&n);
		for(ii=0;ii<n;ii++)
		{
			cin>>a>>b>>c;
			l1=a.size();
			l2=b.size();
			l3=c.size();
			for(i=0;i<l1;i++)
			{
				for(j=0;j<l2;j++)
				{
					for(k=0;k<l3;k++)
						dis[a[i]-'a'][b[j]-'a'][c[k]-'a']=-1;
				}
			}
		}
		printf("Case %d: %d\n",tc,bfs(st,en));
	}
    return 0;
}
