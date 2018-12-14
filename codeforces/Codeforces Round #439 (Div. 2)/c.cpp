#include<bits/stdc++.h>
using namespace std;
#define M 998244353
int dp[5005][5005];
int find(int x, int y) {
	int mx = max(x, y);
	int mn = min(x, y);
	if(mn == 1) {
		return mx + 1;
	}
	
	if(dp[mx][mn] > -1) {
		return dp[mx][mn];
	}
	
	return dp[mx][mn] = (find(mx - 1, mn) + ((long long)mn * find(mx - 1, mn - 1)) %M) % M;
}

int main(){
	int a, b, c;
	memset(dp, -1, sizeof(dp));
	while(scanf("%d %d %d", &a, &b, &c) == 3) {
		int x = find(a, b);
		int y = find(b, c);
		int z = find(c, a);
		printf("%d\n", ((((long long)x * y) % M) * (long long)z)%M);
	}
	return 0;
}
