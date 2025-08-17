//https://cses.fi/problemset/task/1636
#include <iostream>
#include <vector>
using namespace std;
const int INT_MOD = 1e9 + 7;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int &c : coins) {
        cin>>c;
    }
    // sort(coins.begin(), coins.end());
    vector<int> dp(x + 1);
    dp[0] = 1;
    for(int coin : coins) {
        for(int s = 0; s + coin <= x; s++) {
            dp[s + coin] = (dp[s + coin] + dp[s]) % INT_MOD;
        }
    }
    cout<<dp[x];
    return 0;
}