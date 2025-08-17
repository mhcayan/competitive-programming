//https://cses.fi/problemset/task/1635
#include <iostream>
#include <vector>
#include<algorithm>
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
    sort(coins.begin(), coins.end());
    vector<int> dp(x + 1);
    dp[0] = 1;
    for(int s = 1; s <= x; s++) {
        for(auto coin : coins) {
            if(s - coin < 0) break;
            dp[s] = (dp[s] + dp[s - coin]) % INT_MOD;
        }
    }
    cout<<dp[x];
    return 0;
}