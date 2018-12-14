#include<bits/stdc++.h>
using namespace std;
#define SIZE 105
double dp[SIZE][2];
vector<int> edge[SIZE];
int indegree[SIZE];
double funRating[SIZE];
vector<int> takenNodes;

//Returns root of the tree.
//param n = number of nodes in the tree
int findRoot(int n) {
	int i = 0;
	for(; i < n; i++) {
		if(indegree[i] == 0) {
			break;
		}
	}
	return i;
}

double findMaxRating(int cur, int take) {
	
	if(dp[cur][take] > 0) {
		return dp[cur][take];
	}
	
	double ans = 0;
	if(take == 1) { //node 'cur' is taken
		ans += funRating[cur];
		//since node 'cur' is taken, it's child can't be taken. 
		//so, take = 0 for each child
		for(int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			ans += findMaxRating(next, 0);
		}
	} else {  //node 'cur' is not taken
		for(int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			//since, node 'cur' is not taken
			//we need to find the optimal solution 
			//for each child of 'cur'
			//For each child, optimal solution 
			//can be obtained either by taking it(take = 1)
			//or by not taking it(take = 0)
			ans += max(findMaxRating(next, 0), findMaxRating(next, 1));
		}
	}
	dp[cur][take] = ans;
	return dp[cur][take];
}

void findGuestList(int cur, int take) {
	//node 'cur' must not be taken
	if(take == 0) {
		for(int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			findGuestList(next, 1);
		}
	} else { //node 'cur' may be taken
		
		//we got a better solution without taking node 'cur'
		if(dp[cur][0] > dp[cur][1]) {
			for(int i = 0; i <edge[cur].size(); i++) {
				int next = edge[cur][i];
				findGuestList(next, 1);
			}
		} else {
			takenNodes.push_back(cur);
			for(int i = 0; i < edge[cur].size(); i++) {
				int next = edge[cur][i];
				findGuestList(next, 0);
			}
		}
	}
}

int main() {
	int n, u, v, w;
	//n = number of employees(nodes)
	while(scanf("%d", &n) == 1) {
		//Array funRating contains rating of each employee(node)
		for(int i = 0; i < n; i++) {
			scanf("%lf", &funRating[i]);
			dp[i][0] = -1;
			dp[i][1] = -1;
			edge[i].clear();
			indegree[i] = 0;
		}
		//it is assumed that nodes are numbered from 0 to n-1
		//e = number of edges in the tree
		int e = n - 1;
		while(e--) {
			//if there is an edge from u to v, then
			//it indicates that u is the direct supervisor of v,
			scanf("%d %d", &u, &v);
			edge[u].push_back(v);
			indegree[v]++;
		}
		
		int root = findRoot(n);
		printf("Maximum fun rating = %lf\n", findMaxRating(root, 1));
		
		takenNodes.clear();
		//president must be present in the party
		takenNodes.push_back(root);
		
		for(int i = 0; i < edge[root].size(); i++) {
			findGuestList(edge[root][i], 0);
		}
		
		printf("Guest list:[");
		for(int i = 0; i < takenNodes.size(); i++) {
			printf("%d", takenNodes[i]);
			if(i != takenNodes.size() - 1) {
				printf(", ");
			}
		}
		printf("]\n");
	}
	return 0;
}
