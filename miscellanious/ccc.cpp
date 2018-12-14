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
#include<set>
using namespace std;
#define ulong unsigned long
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
int a[103][10004],r,c,i,j,cnt,flag,L[103][10004],R[103][10004],total,mn;
int min(int x,int y)
{
	return x<y?x:y;
}
int main()
{
	char str[10000];
	while(scanf("%d %d",&r,&c)==2)
    {
		getchar();
		flag=0;
		for(i=1;i<=r;i++)
		{
			cnt=0;
			gets(str);
			for(j=0;j<c;j++)
			{
				a[i][j+1]=str[j]-'0';
				if(a[i][j]==1)
					cnt++;
			}
			if(cnt==0)
				flag=1;
		}
		if(flag)
			printf("-1\n");
		else
		{
			for(i=1;i<=r;i++)
			{
				if(a[i][1]==1)
					
				for(j=2;j<=c;j++)
				{
					if(a[i][j]==1)
					{
						R[i][1]=j-1;
						break;
					}
				}
				if(j>c)
					R[i][1]=c;
			}
			for(i=1;i<=r;i++)
			{
				for(j=c-1;j>0;j--)
				{
					if(a[i][j]==1)
					{
						L[i][c]=c-j;
						break;
					}
				}
				if(j==0)
					L[i][c]=c;
			}
			for(i=1;i<=r;i++)
			{
				for(j=2;j<=c;j++)
				{
					if(a[i][j]==1)
						R[i][j]=0;
					else
						R[i][j]=R[i][j-1]-1;
				}
			}
			for(i=1;i<=r;i++)
			{
				for(j=c-1;j>=1;j--)
				{
					if(a[i][j]==1)
						L[i][j]=0;
					else
						L[i][j]=L[i][j+1]-1;
				}
			}
			mn=inf;
			for(j=1;j<=c;j++)
			{
				total=0;
				for(i=1;i<=r;i++)
					total+=min(L[i][j],R[i][j]);
				if(total<mn)
					mn=total;
			}
			printf("%d\n",mn);
			
		}
    }
    return 0;
}
