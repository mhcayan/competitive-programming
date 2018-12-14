#include<bits/stdc++.h>
using namespace std;
#define MX 30000

vector<int> tree[4 * MX];
int a[MX + 5];

int binarySearch(vector<int> &v, int x) {
//	for(int i = 0; i < v.size(); i++) {
//		printf("%d,", v[i]);
//	}
//	printf("\n");
	int beg = 0;
	int end = v.size() - 1;
	while(beg <= end) {
		int mid = (beg + end) >> 1;
		if(x < v[mid]) {
			end = mid - 1;
		} else {
			beg = mid + 1;
		}
	}	
	return v.size() - beg;
}

void init(int node, int beg, int end) {
	if(beg == end) {
		tree[node].push_back(a[beg]);
		return;
	}
	
	int left = node << 1;
	int right = left + 1;
	int mid = (beg + end) >> 1;
	init(left, beg, mid);
	init(right, mid + 1, end);
	
	int p1 = 0, p2 = 0;
	while(p1 < tree[left].size() && p2 < tree[right].size()) {
		if(tree[left][p1] < tree[right][p2]) {
			tree[node].push_back(tree[left][p1++]);
		} else {
			tree[node].push_back(tree[right][p2++]);
		}
	}
	
	while(p1 < tree[left].size()) {
		tree[node].push_back(tree[left][p1++]);
	}
	
	while(p2 < tree[right].size()) {
		tree[node].push_back(tree[right][p2++]);
	}
}

int query(int node, int beg, int end, int i, int j, int x) {
	if(i > end || j < beg) {
		return 0;
	}
	
	if(i <= beg && end <= j) {
		return binarySearch(tree[node], x);
	}
	
	int left = node << 1;
	int right = left + 1;
	int mid = (beg + end) >> 1;
	
	return query(left, beg, mid, i, j, x) + query(right, mid + 1, end, i, j, x);
}

int main() {
	int n, q, i, j, k;
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	init(1, 1, n);
//	for(int i = 1; i <26; i++) {
//		printf("tree[%d] -->> ", i);
//		for(j = 0; j < tree[i].size(); j++) {
//			printf("%d, ", tree[i][j]);
//		}
//		printf("\n");
//	}
	scanf("%d", &q);
	while(q--) {
		scanf("%d %d %d", &i, &j, &k);
		printf("%d\n", query(1, 1, n, i, j, k));
	}
	
	return 0;
}
