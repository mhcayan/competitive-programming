//https://dmoj.ca/problem/dmopc14c4p6
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
#define SZ 500005

vector<int> adj[SZ];
int dp[SZ]; //dp[i] = rank of node i in tree rooted at node 1
multiset<int, greater<int>> dplist[SZ]; //dplist[i] contains list of child along with their rank > pair(rank, child)
int ans[SZ];

void dfs(int u, int p) {
	
	dp[u] = 1;
	for(int v : adj[u]) {
		if(v != p) {
			dfs(v, u);
			dp[u] = max(dp[u], 1 + dp[v]);
			dplist[u].insert(dp[v]);
		}
	}
}

void dfs2(int u, int p, int p_ans = 0) {
	
	ans[u] = max(dp[u], p_ans + 1);
	
	for(int v : adj[u]) {
		if(v == p) {
			continue;
		}		
		
		auto itr = dplist[u].find(dp[v]);
		int tmp = -1;
		if(itr != dplist[u].end()) {
			tmp = *itr;
			dplist[u].erase(itr);
		}
		int u_rank = 1;
		if(!dplist[u].empty()) {
			u_rank = (*dplist[u].begin())+ 1;
		}
		dfs2(v, u, max(u_rank, p_ans + 1));
		if(tmp != -1) {
			dplist[u].insert(tmp);
		}
	}
}

int main() {
	
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    for(int i = 1; i < n; i++) {
    	int u, v;
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
	}
	
	dfs(1, -1);
	dfs2(1, -1);
	for(int i = 1; i <= n; i++) {
		cout<<ans[i]<<endl;
	}
	
    return 0;
}
