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
    //int i,j,k,m,n,cas,tc,cnt,total,ans;
    vector<int> v;
    int n, k;
    while(scanf("%d %d", &n, &k) == 2)
    {
    	v.clear();
    	for(int i = 0; i < n; i++) {
    		int x;
    		scanf("%d", &x);
    		if(x > 0) {
    			v.pb(x);
			}
		}
		sort(v.begin(), v.end());
		int index = 0;
		int lastmin = 0;
		for(int i = 0; i < k; i++) {
			
			if(index < n) {
				printf("%d\n", v[index] - lastmin);
				lastmin = v[index];
				while(index < n && v[index] == lastmin) {
					index++;
				}
			} else {
				printf("0\n");
			}
		}
    }
    return 0;
}

