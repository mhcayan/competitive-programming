//https://judge.yosupo.jp/problem/static_range_sum
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin>>N>>Q;
    vector<long long> v(N);
    for(int i = 0; i < N; i++) {
        cin>>v[i];
        v[i] = i ? v[i - 1] + v[i] : v[i];
    }

    int l, r;
    while(Q--) {
        cin>>l>>r;
        cout<<v[r - 1] - (l ? v[l - 1] : 0)<<endl;
    }
    return 0;
}