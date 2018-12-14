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
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define ff first
#define ss second
#define pii pair<int,int>
#define psi pair<string,int>
#define eps 1e-11
#define mod 100000007

#define sd(a) scanf("%d",&a)
#define sd2(a) scanf("%d %d",&a,&b)
#define slf(a) scanf("%lf",&a)
const int inf=2000000000;
int main()
{
	int R1[50][50],R2[50][50],M[50][50],r1,r2,c1,c2,i,j,k;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(1)
	{
		printf("Number of rows and columns in realation R1(enter 0 0 to exit)\n");
		if(r1==0)
			break;
		scanf("%d %d",&r1,&c1);
		for(i=0;i<r1;i++)
			for(j=0;j<c1;j++)
			    scanf("%d",&R1[i][j]);
		printf("Number of rows and columns in realation R2\n");
		scanf("%d %d",&r2,&c2);
		for(i=0;i<r2;i++)
			for(j=0;j<c2;j++)
			    scanf("%d",&R2[i][j]);
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				M[i][j]=-inf;
				for(k=0;k<c1;k++)
				{
					M[i][j]=max(M[i][j],min(R1[i][k],R2[k][j]));
				}
				printf("%d ",M[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}