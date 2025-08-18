//https://cses.fi/problemset/task/1158

/*
**note**
recurrance:
dp[i][j] = max number of pages considering all books upto index i, with j amount of money
dp[i][j] = if price[i] <= j:
                max(page[i] + dp[i-1][j - price[i]] //take book i
                    dp[i - 1][j]) //don't take book i
            else:
                dp[i - 1][j] //we can't take book i


*/
#include <iostream>
#include <vector>
using namespace std;
const int INT_MOD = 1e9 + 7;
vector<string> grid;

void input(vector<int> &data) {
    for(auto &x : data) {
        cin>>x;
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin>>n>>x;
    vector<int> price(n);
    vector<int> page(n);
    input(price);
    input(page);
    vector<int> dp(x + 1);
    for(int i = 0; i < n; i++) {
        for(int j = x; j; j--) {
            if(price[i] <= j) {
                dp[j] = max(dp[j], page[i] + dp[j - price[i]]);
            }
        }
    }
    cout<<dp[x];
    return 0;
}