//https://codeforces.com/contest/1220/problem/E
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define ff first
#define ss second
#define pii pair<int,int>
#define psi pair<string,int>
#define eps 1e-11
#define mod 100000007
#define endl '\n'
const int inf=2000000000;
#define SZ 200009

int N, M;
int weight[SZ];
vector<int> edge[SZ];
vector<int> leaf_list;
bool vis[SZ];
int par[SZ];
bool taken[SZ];
LL dp[SZ];
bool dfs(int u, int par_u, long long &ans) {

    if(vis[u]) {
        return true;
    }

    vis[u] = true;

    bool is_leaf = true;
    bool can_take = false;
    for(auto v : edge[u]) {
        
        if(v != par_u) {
            par[v] = u;
            if(dfs(v, u, ans))
                can_take = true;
            is_leaf = false;
        }
    }

    if(is_leaf) {
        leaf_list.pb(u);
    }

    if(can_take) {
        ans += weight[u];
        taken[u] = true;
    }

    return can_take;
}

LL find_leaf_weight(int cur) {
    if(taken[cur]) {
        return 0;
    }

    if(dp[cur] > -1) {
        return dp[cur];
    }

    dp[cur] = weight[cur] + find_leaf_weight(par[cur]);
    return dp[cur];
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin>>weight[i];
        par[i] = i;
        dp[i] = -1;
    }

    int u, v;
    while(M--) {
        cin>> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    int s;
    cin>>s;
    LL ans = weight[s];
    vis[s] = true;
    for(int u : edge[s]) {
        if(!vis[u]) {
            par[u] = s;
            dfs(u, s, ans);
        }
    }

    LL mx_leaf_weigth = 0;
    taken[s] = true;

    for(auto leaf : leaf_list) {
        
        LL leaf_weight = find_leaf_weight(leaf);
        if(leaf_weight > mx_leaf_weigth) {
            mx_leaf_weigth = leaf_weight;
        }
    }

    cout<< ans + mx_leaf_weigth;
}
