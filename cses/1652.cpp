//https://cses.fi/problemset/task/1652
#include<vector>
#include<iostream>
#include <climits>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, ans, x1, y1, x2, y2;
    cin>>n>>q;
    vector<vector<int>> dp(n, vector<int> (n, 0)); //dp[i][j] = #tree in rectangle (1, 1) -> (i, j)
    string line;
    for(int i = 0; i < n; i++) {
        cin>>line;
        int row_tree_cnt = 0;
        for(int j = 0; j < n; j++) {
            row_tree_cnt += (line[j] == '*');
            dp[i][j] = (i ? dp[i - 1][j] : 0) + row_tree_cnt;
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    while(q--) {
        cin>>x1>>y1>>x2>>y2;
        x1--;
        x2--;
        y1--;
        y2--;
        ans = dp[x2][y2];

        if(x1 - 1 >= 0) {
            ans -= dp[x1 - 1][y2];
        }

        if(y1 - 1 >= 0) {
            ans -= dp[x2][y1 - 1];
            if(x1 - 1 >= 0) {
                ans += dp[x1 - 1][y1 - 1];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
