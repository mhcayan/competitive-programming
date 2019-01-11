//https://www.codechef.com/problems/COAD03
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int dp[1001];
int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cas, q;
    cin>>cas;
    for(int i = 1; i < 1001; i++) {
    	if(i & 1) {
    		dp[i] = dp[i-1] + 1;
		} else {
			dp[i] = min(dp[i-1] + 1, dp[i>>1] + 2);
		}
	}
    while(cas--) {
    	cin>>q;
    	cout<<dp[q]<<endl;
	}
	return 0;
}
