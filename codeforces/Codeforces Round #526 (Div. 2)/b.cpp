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
const ULL longinf = 20000000000000L;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //int i,j,k,m,n,cas,tc,cnt,total,ans;
    LL n, s, a;
    while(scanf("%I64d %I64d", &n, &s) == 2)
    {
    	LL sum = 0;
    	LL min = longinf;
    	for(int i = 0; i < n; i++) {
    		scanf("%I64d", &a);
    		sum += a;
    		if(min > a) {
    			min = a;
			}
		}
		if(sum < s) {
			printf("-1\n");
		} else {
			ULL rem = sum - s;
			ULL perglass = rem / n;
			if(min < perglass) {
				printf("%I64d\n", min);
			} else {
				printf("%I64d\n", perglass);
			}
		}
		
    }
    return 0;
}

