#include<bits/stdc++.h>
using namespace std;
#define MX 100000
struct data{
	int sum;
	bool prop;
};

data tree[4 *MX];

void init(int node, int beg, int end) {
	tree[node].sum = 0;
	tree[node].prop = false;
	if(beg == end) {
		return;
	}
	int left = node << 1;
	int right = left + 1;
	int mid = (beg + end) >> 1;
	init(left, beg, mid);
	init(right, mid + 1, end);
}

void update(int node, int beg, int end, int i, int j) {
	if(j < beg || i > end) {
		return;
	}
	
	if(i <= beg && end <= j) {
		tree[node].prop = !tree[node].prop;
		tree[node].sum = end - beg + 1 - tree[node].sum;
		return;
	}
	
	int left = node << 1;
	int right = left + 1;
	int mid = (beg + end) >> 1;
	update(left, beg, mid, i, j);
	update(right, mid + 1, end, i, j);
	tree[node].sum = tree[node].prop ? (end - beg + 1)- (tree[left].sum + tree[right].sum)
	: tree[left].sum + tree[right].sum;
}

int query(int node, int beg, int end, int i, int j, bool carry) {
	if(j < beg || i > end) {
		return 0;
	}
	
	if(i <= beg && end <= j) {
		return carry ? (end - beg + 1) - tree[node].sum : tree[node].sum;
	}
	
	int left = node << 1;
	int right = left + 1;
	int mid = (beg + end) >> 1;
	return query(left, beg, mid, i, j, carry ^ tree[node].prop) +
	       query(right, mid + 1, end, i, j, carry ^ tree[node].prop);
}


int main(){
	int N, M, type, x, y;
	while(scanf("%d %d", &N, &M) == 2) {
		init(1, 1, N);
		while(M--) {
			scanf("%d %d %d", &type, &x, &y);
			if(type) {
				printf("%d\n", query(1, 1, N, x, y, false));
			} else{
				update(1, 1, N, x, y);
			}
		}
	}
	return 0;
}
