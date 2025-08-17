//https://cses.fi/problemset/task/1638
#include <iostream>
#include <vector>
using namespace std;
int n;
const int INT_MOD = 1e9 + 7;
vector<string> grid;
vector<vector<int>> dp; 
int find(int x, int y) {
    if(x == n - 1 && x == y) {
        return 1;
    }

    if(x >= n || y >= n || grid[x][y] == '*') return 0;

    int &ret = dp[x][y];
    if(ret > -1) return ret;

    return ret = (find(x + 1, y) + find(x, y + 1)) % INT_MOD;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    grid.resize(n);
    for(int i = 0; i < n; i++) {
        cin>>grid[i];
    }
    if(grid[n - 1][n - 1] == '*' || grid[0][0] == '*') {
        cout<<0;
    } else {
        dp.resize(n, vector<int> (n, -1));
        cout<<find(0, 0);
    }
    return 0;
}