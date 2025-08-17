//https://cses.fi/problemset/task/1637
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    int temp, d;
    for(int i = 1; i <= n; i++) {
        temp = i;
        while(temp) {
            d = temp % 10;
            if(d && dp[i - d] >= 0) {
                dp[i] = min(dp[i], dp[i - d] + 1);
            } 
            temp = temp / 10;
        }
    }
    cout<<dp[n];
    return 0;
}