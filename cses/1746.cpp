//https://cses.fi/problemset/task/1746
#include <iostream>
#include <vector>
using namespace std;
const int INT_MOD = 1e9 + 7;
int n, m;
vector<int> x;
vector<vector<int>> dp;

void add_self(int &x, int val) {
    x = x + val;
    if(x >= INT_MOD) {
        x -= INT_MOD;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    x.resize(n);
    dp.resize(n, vector<int> (m + 2));
    for(auto &val : x) {
        cin>>val;
    }

    if(x[0]) {
        dp[0][x[0]] = 1;
    } else {
        for(int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    }
    for(int i = 1; i < n; i++) {
        if(x[i]) {
            for(int delta = -1; delta < 2; delta++) {
                add_self(dp[i][x[i]], dp[i - 1][x[i] + delta]);
            }
        } else {
            for(int val = 1; val <= m; val++) {
                for(int delta = -1; delta < 2; delta++) {
                    add_self(dp[i][val], dp[i - 1][val + delta]);
                }
            }
        }
    }
    int ans = 0;
    for(int val = 1; val <= m; val++) {
        add_self(ans, dp[n - 1][val]);
    }
    cout<<ans;
    return 0;
}