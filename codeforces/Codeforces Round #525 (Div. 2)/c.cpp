#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
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
const int inf=2000000000;
const int M = 100000;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //int i,j,k,m,n,cas,tc,cnt,total,ans;
    int n, a[2005];
    while(scanf("%d", &n) == 1)
    {
    	for(int i = 1; i <= n; i++) {
    		scanf("%d", &a[i]);
    		a[i] += M;
		}
		printf("%d\n", n + 1);
		printf("1 %d %d\n", n, M);
		for(int i = 0; i < n; i++)
		{
			printf("2 %d %d\n", i + 1, a[i + 1] - i);
		}
    }
    return 0;
}

