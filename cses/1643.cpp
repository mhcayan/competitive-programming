//https://cses.fi/problemset/task/1643
#include<vector>
#include<iostream>
#include <climits>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, val;
    long long prefix_sum = 0, ans, min_prefix_sum = 0;
    cin>>n;
    ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        cin>>val;
        prefix_sum += val;
        ans = max(ans, prefix_sum - min_prefix_sum);
        min_prefix_sum = min(prefix_sum, min_prefix_sum);
    }
    cout<<ans<<endl;
    return 0;
}