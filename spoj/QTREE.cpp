//https://www.spoj.com/problems/QTREE/
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
#define SZ 10005
#define LOG_SZ 16
int N;
vector<int> edge[SZ];
vector<int> cost[SZ];
vector<int> edge_list[SZ];
int par[SZ][LOG_SZ]; //sparse table
int L[SZ]; //node level
int tree_size[SZ]; //size of subtree
int chainCnt;
int chainNo[SZ];
int chainHead[SZ];
int base_array[SZ];
int base_array_pos[SZ];
int ptr;
int stree[SZ * 4];
int edgeEnd[SZ];

void print_base() {
	cout<<"Base array: ";
	for(int i = 0; i <= ptr; i++) {
		cout<<base_array[i]<<' ';
	}
	cout<<endl;
}

void dfs(int u, int p = -1, int level = 0) {
	
	par[u][0] = p;
	L[u] = level;
	tree_size[u] = 1;
	
	for(int i = 0; i < edge[u].size(); i++) {
		int v = edge[u][i];
		if(v != p) {
			int vcost = cost[u][i];
			int cur_edge = edge_list[u][i];
			edgeEnd[cur_edge] = v; // end point of edge. needed for the update of base_array for update query
			dfs(v, u, L[u] + 1);
			tree_size[u] += tree_size[v];
		}
	}
}

//build sparse table for LCA
void buildLCA() {
	
	for(int j = 1; (1 << j) < N; j++) {
		for(int i = 1; i <= N; i++) {	
			if(par[i][j-1] != -1) {
				par[i][j] = par[par[i][j-1]][j-1];
			}
			else {
				par[i][j] = -1;
			}
		}
	}
}

int getLCA(int p, int q) {

	if(L[p] < L[q]) swap(p, q);
	
	int lg; for(lg = 1; (1 << lg) <= L[p]; lg++); lg--;
	
	for(int i = lg; i >=0; i--) {
		if(L[p] - (1 << i) >= L[q]) {
			p = par[p][i];
		}
	}
	
	if(p == q) return p;
	
	for(int i = lg; i >= 0; i--) {
		if(par[p][i] != -1 && par[p][i] != par[q][i]) { 
			p = par[p][i];
			q = par[q][i];
		}
	}
	
	return par[p][0];
}

void HLD(int u, int p = -1, int c = 0) {
	
	if(chainHead[chainCnt] == -1) {
		chainHead[chainCnt] = u;
	}
	
	chainNo[u] = chainCnt;
	ptr++;
	base_array[ptr] = c;
	base_array_pos[u] = ptr;
	
	//find special child
	int sc = -1; //special child
	int sc_cost; //edge(incoming edge) weight of special child
	for(int i = 0; i < edge[u].size(); i++) {
		int v = edge[u][i];
		if(v != p) {
			if(sc == -1 || tree_size[v] > tree_size[sc]) {
				sc = v;
				sc_cost = cost[u][i];
			}
		}
	}
	
	if(sc == -1) return; //u is leaf node.
	
	HLD(sc, u, sc_cost); //append special child to current chain
	
	for(int i = 0; i < edge[u].size(); i++) { //creating new chain for each of the non-special child
		int v = edge[u][i];
		if(v != p && v != sc) {
			chainCnt++;
			HLD(v, u, cost[u][i]);
		}
	}
}

void init() {
	
	for(int i = 0; i <= N; i++) {
		edge[i].clear();
		cost[i].clear();
		edge_list[i].clear();
		chainHead[i] = -1;
	}
	
	chainCnt = 0;
	ptr = -1; //base_array pointer(index)
}

void build_stree(int cur, int b, int e) {
	
	if(b == e) {
		stree[cur] = base_array[b];
		return;
	}
	
	int mid = (b + e) / 2;
	int left = cur * 2;
	int right = left + 1;
	build_stree(left, b, mid);
	build_stree(right, mid + 1, e);
	stree[cur] = stree[left] > stree[right] ? stree[left] : stree[right];
}

int query_stree(int cur, int b, int e, int qb, int qe) {
	
	if(qe < b || qb > e) return 0;
	
	if(qb <= b && e <= qe) return stree[cur];
	
	int left = cur * 2;
	int right = left + 1;
	int mid = (b + e) / 2;
	int ans1 = query_stree(left, b, mid, qb, qe);
	int ans2 = query_stree(right, mid + 1, e, qb, qe);
	return ans1 > ans2 ? ans1 : ans2;
}

void update_stree(int cur, int b, int e, int index, int value) {
	
	if(index < b || index > e) return;
	
	if(index == b && b == e) {
		stree[cur] = value;
		base_array[b] = value;
		return;
	}
	
	int left = cur * 2;
	int right = left + 1;
	int mid = (b + e) / 2;
	update_stree(left, b, mid, index, value);
	update_stree(right, mid + 1, e, index, value);
	stree[cur] = stree[left] > stree[right] ? stree[left] : stree[right];
}

int query_up(int p, int lca) {
	
	if(p == lca) return 0;
	int lca_chain = chainNo[lca];	
	int ans = 0;
	while(1) {
		int p_chain = chainNo[p];
		if(p_chain == lca_chain) { //p and lca are in the same chain
			if(p == lca) break;
			int ans2 = query_stree(1, 1, ptr, base_array_pos[lca] + 1, base_array_pos[p]);
			if(ans2 > ans) ans = ans2;
			break;
		} else {
			int ans2 = query_stree(1, 1, ptr, base_array_pos[chainHead[p_chain]], base_array_pos[p]);
			if(ans2 > ans) ans = ans2;
			p = par[chainHead[p_chain]][0]; //move up to the next chain
		}
	}
	return ans;
}

int query(int a, int b) {
	int lca = getLCA(a,b);
	int ans1 = query_up(a, lca);
	int ans2 = query_up(b, lca);
	return ans1 > ans2 ? ans1 : ans2;
}

void change(int edgeNo, int value) {
	
	int endPoint = edgeEnd[edgeNo]; // endPoint of given edge in the dfs build tree
	int indx = base_array_pos[endPoint]; // position/index of the edge in base_array
	update_stree(1, 1, ptr, indx, value);
//	print_base();
}

void solve() {

	cin>>N;
	init();
	int u,v,c;
	for(int i = 1; i < N; i++) {
		cin>>u>>v>>c;
		edge[u].pb(v);
		edge[v].pb(u);
		cost[u].pb(c);
		cost[v].pb(c);
		edge_list[u].pb(i); 
		edge_list[v].pb(i);
	}
	
	dfs(1);
	buildLCA();
	HLD(1);
	build_stree(1, 1, ptr); //build segment tree from the base_array
	string q;
	int a,b;
//	print_base();
	while(1) {
		cin>>q;
		if(q[0] == 'Q') {
			cin>>a>>b;
			cout<<query(a,b)<<endl;
		} else if(q[0] == 'C') {
			cin>>a>>b;
			change(a,b);
		} else {
			break;
		}
	}
}

int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL);
	int cas; cin>>cas; for(int tc = 1; tc <= cas; tc++) solve();
    //solve();
    return 0;
}
