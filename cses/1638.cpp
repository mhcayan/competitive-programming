//https://cses.fi/problemset/task/1638
#include <iostream>
#include <vector>
using namespace std;
const int INT_MOD = 1e9 + 7;
vector<string> grid;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string grid;
    cin>>grid;
    vector<int> dp(n);
    for(int i = 0; grid[i] && grid[i] == '.'; i++) {
        dp[i] = 1;
    }

    for(int i = 1; i < n; i++) {
        cin>>grid;
        if(grid[0] == '*') dp[0] = 0;
        for(int j = 1; j < n; j++) {
            if(grid[j] == '.') {
                dp[j] = dp[j] + dp[j - 1];
                if(dp[j] > INT_MOD) dp[j] -= INT_MOD;
            } else {
                dp[j] = 0;
            }
        }
    }
    cout<<dp[n - 1];
    return 0;
}