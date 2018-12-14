#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define ff first
#define ss second
#define eps 1e-11
#define mod 100000007
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define REP(I, A, B) for (int I = (A); I < (B); ++I)
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VLL;
const int inf=2000000000;
int main() {
	LL n, total_size, capacity, a, b;
	int i;
	VLL v;
	while(scanf("%I64d %I64d", &n, &capacity) == 2) {
		v.clear();
		total_size = 0;
		for(i = 0; i < n; i++) {
			scanf("%I64d %I64d", &a, &b);
			v.pb(a-b);
			total_size += a;
		}
		if(total_size <= capacity) {
			printf("0\n");
		} else {
			sort(v.begin(), v.end(), greater<LL>());
			for(i = 0; i < n; i++) {
				total_size -= v[i];
				if(total_size <= capacity) {
					break;
				}
			}
			if(i == n) {
				printf("-1\n");
			} else {
				printf("%d\n", i + 1);
			}
		}
		
	}
	return 0;
}
