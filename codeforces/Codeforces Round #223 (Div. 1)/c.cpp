#include<bits/stdc++.h>
#define MX 1000000
using namespace std;
char str[MX + 5];
struct data {
	int s;
	int l;
	int r;
	data() {
		s = -1;
		l = 0;
		r = 0;
	}
};

data tree[MX * 4];
void init(int node, int beg, int end) {
	if(beg == end) {
		tree[node].s = 0;
		if(str[beg] == '(') {
			tree[node].l = 1;
			tree[node].r = 0;
		} else {
			tree[node].r = 1;
			tree[node].l = 0;
		}
		return;
	}
	
	int left = node << 1;
	int right = left + 1;
	int mid = (beg + end) >> 1;
	init(left, beg, mid);
	init(right, mid + 1, end);
	int mn = min(tree[left].l, tree[right].r);
	tree[node].s = tree[left].s + tree[right].s + 2 * mn;
	tree[node].l = tree[left].l - mn + tree[right].l;
	tree[node].r = tree[left].r + tree[right].r - mn;
}

data query(int node, int beg, int end,  int i, int j) {
	if(j < beg || i > end) {
		data x;
		x.s = -1;
		return x;
	}
	
	if(i <= beg && end <= j) {
		return tree[node];
	}
	
	int left = node << 1;
	int right = left + 1;
	int mid = (beg + end) >> 1;
	data l_data = query(left, beg, mid, i, j);
	data r_data = query(right, mid + 1, end, i, j);
	
	if(l_data.s == -1) {
		return r_data;
	}
	
	if(r_data.s == -1) {
		return l_data;
	}
	
	data new_data;
	int mn = min(l_data.l, r_data.r);
	new_data.s = r_data.s + l_data.s + 2 * mn;
	new_data.l = l_data.l - mn + r_data.l;
	new_data.r = l_data.r + r_data.r - mn;
	return new_data;
}


int main() {
	int q, i, j;
	while(scanf("%s", str + 1) == 1) {
		int n = strlen(str + 1);
		init(1, 1, n);
		scanf("%d", &q);
		while(q--) {
			scanf("%d %d", &i, &j);
			data ans = query(1, 1, n , i, j);
			if(ans.s == -1)
			   ans.s = 0;
			printf("%d\n", ans.s);
		}
	}
	return 0;
}
