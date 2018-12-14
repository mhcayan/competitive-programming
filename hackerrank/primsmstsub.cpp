//https://www.hackerrank.com/challenges/primsmstsub

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define MX 3000 + 3

struct data{
	int u, v, c;
	bool operator < (const data &p) const {
		return c < p.c;
	}
};

vector<data> edge_list;
int par[MX];

int find(int u){
	if(u == par[u]){
		return u;
	}
	return par[u] = find(par[u]);
}

int mst(int N){
	int ans = 0, i, paru, parv;
	for(i = 1; i <= N; i++){
		par[i] = i;
	}
	for(i = 0; i < edge_list.size(); i++){
		paru = find(edge_list[i].u);
		parv = find(edge_list[i].v);
		if(parv != paru){
			ans += edge_list[i].c;
			par[paru] = parv;
			N--;
			if(N < 2){
				break;
			}
		}
	}
	return ans;
}

int main(){
	int N, E, i;
	data edge;
	while(scanf("%d %d", &N, &E) == 2){
	    for(i = 0; i < E; i++){
		    scanf("%d %d %d", &edge.u, &edge.v, &edge.c);
			edge_list.push_back(edge);
		}
		sort(edge_list.begin(), edge_list.end());
		scanf("%d", &i); // i is source
		printf("%d\n",mst(N));
	}
	return 0;
}
