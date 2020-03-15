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
#define endl '\n'
const int inf=2000000000;
#define SZ 2005

int n, h, l ,r, a[SZ], dp[SZ][SZ];

inline bool isGood(int t) {
	return l <= t && t <= r;
}

int find(int i, int wt) {
	
	if(i == n) {
		return 0;
	}
	
	if(dp[i][wt] > -1) {
		return dp[i][wt];
	}
	
	int st = (wt + a[i]) % h;
	int l = find(i + 1, st);
	if(isGood(st)) {
		l += 1;
	}
	
	st = (wt + a[i] - 1) % h;
	int r = find(i + 1, st);
	if(isGood(st)) {
		r += 1;
	}
	
	dp[i][wt] = max(l,r);
	return dp[i][wt];
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> h >> l >> r;
    SET(dp);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
	}
	
	cout<<find(0, 0)<<endl;
	
	return 0;
}
