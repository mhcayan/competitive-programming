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
struct edge_data {
    int v;
    int flow;
    int res;
    int rev_index;
    edge_data(int v, int flow, int res, int rev_index) {
        this->v = v;
        this->flow = flow;
        this->res = res;
        this->rev_index = rev_index;
    }

    string toString() {
        return "v: " + to_string(v) + ", " +
                "flow: " + to_string(flow) + ", " +
                "res: " + to_string(res) + ", " +
                "rev_index: " + to_string(rev_index) + ", ";
    }
};

vector<edge_data> edge_list[500];
int V, E;
pii par[500];
bool vis[500];
bool path_exists(int s, int t) {

    for(int i = 0; i < V; i++) {
        vis[i] =  false;
    }
    queue<int> qq;
    qq.push(s);
    vis[s] = true;
    int u, v;
    while(!qq.empty()) {
        u = qq.front();
        qq.pop();
        for(int i = 0; i < edge_list[u].size(); i++) {
            edge_data edge = edge_list[u][i];
            if(!vis[edge.v] && edge.res > 0) {

                par[edge.v] = make_pair(u, i); // node u's i-th child is v
                if(edge.v == t) 
                    return true;
                qq.push(edge.v);
                vis[edge.v] = true;
            }
        }
    }
   
    return false;
}

//find the edge with minimum capacity in our augmenting path
int find_bottle_neck_cap(int s, int t) {
    int min_cap = inf;
    while(t != s) {
        pii p = par[t];
        //p.first is the parent of t 
        //p.second is the position of t in it's parent's adjacency list
        if(edge_list[p.first][p.second].res < min_cap) {
            min_cap = edge_list[p.first][p.second].res;
        }
        t = p.first;
    }
    return min_cap;
}

//update the residual capacity and flow in the edges along the augmenting path
void update_graph(int s, int t, int flow) {
    while(t != s) {
        pii p = par[t];
        edge_list[p.first][p.second].flow += flow;
        edge_list[p.first][p.second].res -= flow;
        //increase residual capacity of opposite edge
        edge_list[t][edge_list[p.first][p.second].rev_index].res += flow;
        t = p.first;
    }
}
int main() {
    //ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>V>>E;
    int u, v, c;
    for(int i = 0; i < V; i++) {
        edge_list[i].clear();
    }
    for(int i = 0; i < E; i++) {
        cin>>u>>v>>c;
        edge_data edge1(v, 0, c, edge_list[v].size());                                           
        edge_data edge2(u, 0, 0, edge_list[u].size());
        edge_list[u].push_back(edge1);                                            
        edge_list[v].push_back(edge2);
    }

    int source, sink;
    cin>>source>>sink;

    int max_flow = 0;
    
    while(path_exists(source, sink)) {
        int bottle_neck_cap = find_bottle_neck_cap(source, sink);
        cout<<"bottle-neck: " << bottle_neck_cap<<endl;
        update_graph(source, sink, bottle_neck_cap);
        max_flow += bottle_neck_cap;
    }
    cout<<"Max flow: " << max_flow;
    return 0;
}