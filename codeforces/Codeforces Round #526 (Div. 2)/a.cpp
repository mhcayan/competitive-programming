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
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a[105];
    int i,j,k,m,n,cas,tc,cnt,total,ans;
    while(scanf("%d", &n) == 1)
    {
    	for(i = 0; i < n; i++) {
    		scanf("%d", &a[i]);
		}
		int min = inf;
		for(i = 0; i < n; i++) {
			int cost = 0;
			for(j = 0; j < n; j++) {
				cost += a[j] * (abs(i - j) + j + i + i + j + abs(i - j));
			}
			if(cost < min) {
				min = cost;
			}
		}
		printf("%d\n", min);
    }
    return 0;
}

