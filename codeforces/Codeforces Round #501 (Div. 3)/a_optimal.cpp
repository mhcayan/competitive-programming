#include<bits/stdc++.h>
#define M 1005
using namespace std;
bool TREE[M*3];

void update(int node, int b, int e, int i, int j) {
	
	if(i <= b && e <= j) {
		TREE[node] = true;
		return;
	}
	
	if(j < b || e < i) {
		return;
	}
	
	int mid = (b + e) / 2;
	update(node * 2, b, mid, i, j);
	update(node * 2 + 1, mid + 1, e, i, j);
}

void init(int node, int b, int e) {
	TREE[node] = false;
	if(b == e) {
		return;
	}
	int mid = (b + e) / 2;
	init(node * 2, b, mid);
	init(node * 2 + 1, mid + 1, e);
}

bool find(int node, int b, int e, int x) {
	
	if(x < b || e < x) {
		return false;
	}
	
	if(TREE[node]) {
		return true;
	}
	
	if(b == e) {
		return TREE[node];
	}
	
	int mid = (b + e) / 2;
	return find(node * 2, b, mid, x) || find(node * 2 + 1, mid + 1, e, x);
}

int main() {
	int i, j, m, n, x, y;
	while(scanf("%d %d", &m, &n) == 2) {
		for(i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			update(1, 1, n, x, y);
		}
		vector<int> ans;
		for(i = 1; i <= n; i++) {
			if(!find(1, 1, n, i)) {
				ans.push_back(i);
			}
		}
		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		init(1, 1, n);
	}
	return 0;
}
