//https://www.codechef.com/problems/TOURISTS
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
#define SZ 100005

int N, E;

multiset<pii> edge[SZ];
vector<bool> vis(SZ);
vector<pii> edge_list;

void find_euler_path(int u) {
	
	while(!edge[u].empty()) {
		pii vv = *(edge[u].begin());
		int v = vv.ff;
		int edge_no = vv.ss;
		
		edge[u].erase(edge[u].begin());
		edge[v].erase(pii(u, edge_no));
		if(edge_list[edge_no].ff != u) {
			swap(edge_list[edge_no].ff, edge_list[edge_no].ss);
		}
		find_euler_path(v);
	}
}

void dfs(int u) {
	vis[u] = true;
	for(pii vv : edge[u]) {
		int v = vv.ff;
		if(!vis[v]) {
			dfs(v);
		}
	}
}

int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>N>>E;
    
    for(int i = 0; i < E; i++) {
    	int u, v;
    	cin>>u>>v;
    	edge[u].insert(pii(v,i));
    	edge[v].insert(pii(u,i));
    	edge_list.pb(pii(u,v));
	}
	
	for(int i = 1; i <= N; i++) {
		vis[i] = false;
		if(edge[i].size() % 2 != 0) {
			cout<<"NO"<<endl;
			return 0;
		}
	}
	
	dfs(1);
	for(int i = 1; i <= N; i++) {
		if(vis[i] == false) {
			cout<<"NO"<<endl;
			return 0;
		}
	}
	
	find_euler_path(1);
	//reverse(path.begin(), path.end());
	cout<<"YES"<<endl;
	for(pii e : edge_list) {
		cout<<e.ff<< ' ' <<e.ss<< endl;
	}
	
    return 0;
}
