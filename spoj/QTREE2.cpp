//https://www.spoj.com/problems/QTREE2/
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
bool vis[SZ];
int L[SZ]; //node level
vector<int> edge[SZ];
vector<int> cost[SZ];
int par[SZ][20];
int dis[SZ];
int N;

void dfs(int cur) {
	vis[cur] = true;
	for(int i = 0; i < edge[cur].size(); i++) {
		int next = edge[cur][i];
		if(!vis[next]) {
			par[next][0] = cur;
			L[next] = L[cur] + 1; //level
			dis[next] = dis[cur] + cost[cur][i];
			dfs(next);
		}
	}
}

void initDFS() {
	int root = 1;
	L[root] = 0; //node level
	dis[root] = 0; //distance from root
	par[root][0] = -1;
	for(int i = 1; i <= N; i++) {
		vis[i] = false;
	}
}

void init() {

	for(int i = 1; i <= N; i++) {
		edge[i].clear();
		cost[i].clear();
	}
	initDFS();
}

void buildLCA() {
	
	for(int j = 1; (1 << j) < N ; j++) {
		
		for(int i = 1; i <= N; i++) {
			
			if(par[i][j-1] != -1) {
				par[i][j] = par[par[i][j-1]][j-1];
			} else {
				par[i][j] = -1;
			}
		}
	}
}

int findLCA(int p, int q) {
	
	if(L[p] < L[q]) {
		swap(p,q);
	}
	
	//int lg ; for( lg = 1 ; (1 << lg) <= L[p] ; ++lg ); lg--;
	for(int i = log2(L[p]); i >= 0; i--) {
		if(L[p] - (1 << i) >= L[q]) {
			p = par[p][i];
		}
	}
	
	if(p == q) return p;
	
	for(int i = log2(L[p]); i >= 0 ; i--) {
		if(par[p][i] != -1 && par[p][i] != par[q][i]) {
			p = par[p][i];
			q = par[q][i];
		}
	}
	
	return par[p][0];
}

int hopCount(int lca, int p) {
	return L[p] - L[lca];
}

int findDIST(int p, int q) {
	int lca = findLCA(p, q);
	return dis[p] + dis[q] - 2 * dis[lca];
}

int findk(int p, int k) {
	
	if(k == 1) {
		return p;
	}

/*	int lg;
	for(lg = 1; (1 << lg) <= L[p]; lg++); lg--; */
	
	k--;
	for(int i = log2(L[p]); i >= 0; i--) {
		if((1<<i) <=k) {
			p = par[p][i];
			k -= (1<<i);
		}
	}
	return p;
}


int findKTH(int p, int q, int k) {
	int lca = findLCA(p, q);
	if(k <= L[p] - L[lca] + 1) { //k th node is in the path from p to lca
		return findk(p, k);
	} else {
		int phop = hopCount(lca, p);
		int qhop = hopCount(lca, q);
		int totalNode = phop + qhop + 1; //number of nodes in the path from p to q
		k = totalNode - k + 1;
		return findk(q, k);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
    int cas;
    cin>>cas;
    while(cas--) {
    	cin>>N;
    	init();
    	int n1, n2,c;
    	for(int i = 1; i < N; i++) {
    		cin>>n1>>n2>>c;
    		edge[n1].pb(n2);
    		edge[n2].pb(n1);
    		cost[n1].pb(c);
    		cost[n2].pb(c);
		}

		dfs(1);
		buildLCA();
		string q;
		int a, b, k;
		while(true) {
			cin>>q;
			if(q == "DIST") {
				cin>>a>>b;
				cout<<findDIST(a,b)<<endl;
			} else if(q == "KTH") {
				cin>>a>>b>>k;
				cout<<findKTH(a,b, k)<<endl;
			} else {
				break;
			}
		}
		cout<<endl;
	}
    return 0;
}
