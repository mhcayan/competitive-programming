#include<bits/stdc++.h>
using namespace std;
#define MX 100000
struct data {
	long long sum;
	long long prop;
};

data Tree[4 * MX];

void init(long long node, long long b, long long e) {
	Tree[node].prop = 0;
	Tree[node].sum = 0;
	if(b == e) {
		return;
	}
	long long left = node << 1;
	long long right = left + 1;
	long long mid = (b + e) >> 1;
	init(left, b, mid);
	init(right, mid + 1, e);
}

void update(long long node, long long b, long long e, long long i, long long j, long long v) {
	if(j < b || i > e) {
		return;
	}
	
	if(i <= b && e <= j) {
		Tree[node].prop += v;
		Tree[node].sum += (e - b + 1) * v;
		return;
	}
	
	long long left = node << 1;
	long long right = left + 1;
	long long mid = (b + e) >> 1;
	update(left, b, mid, i, j, v);
	update(right, mid + 1, e, i, j, v);
	Tree[node].sum = Tree[left].sum + Tree[right].sum + (e - b + 1) * Tree[node].prop;
}

long long query(long long node, long long b, long long e, long long i, long long j, long long carry = 0) {
	if(j < b || i > e) {
		return 0;
	}
	
	if(i <= b && e <= j) {
		return Tree[node].sum + carry * (e - b + 1);
	}
	
	long long left = node << 1;
	long long right = left + 1;
	long long mid = (b + e) >> 1;
	return query(left, b, mid, i, j, carry + Tree[node].prop) 
	+ query(right, mid + 1, e, i, j, carry + Tree[node].prop);
}

int main() {
	long long cas, N, C, type, p, q, v;
	scanf("%I64d", &cas);
	while(cas--) {
		scanf("%I64d %I64d", &N, &C);
		init(1, 1, N);
		while(C--) {
			scanf("%I64d %I64d %I64d", &type, &p, &q);
			if(type == 0) {
				scanf("%I64d", &v);
				update(1, 1, N, p, q, v);
			} else {
				printf("%I64d\n", query(1, 1, N, p, q, 0));
			}
		}
	}
	return 0;
}
