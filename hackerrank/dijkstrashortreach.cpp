// https://www.hackerrank.com/challenges/dijkstrashortreach
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define MX 3000 + 3
#define inf 1e9

vector<int>edge[MX];
vector<int>cost[MX];
int dis[MX];

struct data{
	int node, dist;
	bool operator < (const data &p) const {
		return dist > p.dist;
	}
};

void djkstr(int s, int N){
	int i;
	for(i = 1; i <= N; i++){
		dis[i] = inf;
	}
	priority_queue<data>q;
	data u, v;
	dis[s] = 0;
	u.node = s;
	u.dist = 0;
	q.push(u);
	while(!q.empty()){
		u = q.top();
		q.pop();
		for(i = 0; i < edge[u.node].size(); i++){
			v.node = edge[u.node][i];
			v.dist = dis[u.node] + cost[u.node][i];
			if(v.dist < dis[v.node]){
				dis[v.node] = v.dist;
				q.push(v);
			}
		}
	}	
}

int main(){
	int N, E, cas, u, v, c, i, s;
	scanf("%d", &cas);
	while(cas--){
		scanf("%d %d", &N, &E);
		for(i = 1; i <= N; i++){
			edge[i].clear();
			cost[i].clear();
		}
		while(E--){
			scanf("%d %d %d", &u, &v, &c);
			edge[u].push_back(v);
			edge[v].push_back(u);
			cost[u].push_back(c);
			cost[v].push_back(c);
		}
		scanf("%d", &s);
		djkstr(s, N);
		for(i = 1; i <= N; i++){
			if(i != s){
				if(dis[i] != inf){
					printf("%d ", dis[i]);
				}else{
					printf("-1 ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
