#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int N;
const int M = 1e5;
int a[M + 2];
int dp[M + 2][4];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cas;
    cin>>cas;
    while(cas--) {
        cin>>N;
        for(int i = 0; i < N; i++) {
            cin>>a[i];
        }

        dp[0][1] = a[0];
        for(int i = 1; i < N; i++) {
            dp[i][1] = max(dp[i - 1][1] - 1, a[i]);
        }

        dp[1][2] = a[0] + a[1] - 1;
        for(int i = 2; i < N; i++) {
            dp[i][2] = max(dp[i - 1][2] - 1, dp[i - 1][1] + a[i] - 1);
        }

        dp[2][3] = a[0] + a[1] + a[2] - 2;
        int ans = dp[2][3];
        for(int i = 3; i < N; i++) {
            dp[i][3] = max(dp[i - 1][3] - 1, dp[i - 1][2] + a[i] - 1);
            ans = max(ans, dp[i][3]);
        }
        cout<<ans<<endl;
    }

    return 0;
}