#include<bits/stdc++.h>
using namespace std;
struct Query{
	int left;
	int right;
	int pos;
	int block;
};
#define MX 200005 
#define MX_VALUE 1000000
Query queries[MX];
int arr[MX];
int cnt[MX_VALUE + 5];
long long output[MX];

bool cmp(Query a, Query b) {
	if(a.block == b.block) {
		return a.right < b.right;
	}
	return a.block < b.block;
}

void moveLeftPointer(int &beg, int &L, int arr[], long long &ans) {
	while(beg < L) {
		ans = ans - 2 * arr[beg] * cnt[arr[beg]] + arr[beg];
		cnt[arr[beg]]--;
		beg++;
	}
	
	while(L < beg) {
		beg--;
		ans = ans + 2 * arr[beg] * cnt[arr[beg]] + arr[beg];
		cnt[arr[beg]]++;
	}
}

void moveRightPointer(int &end, int R, int arr[], long long &ans) {
	while(end <= R) {
		ans = ans + 2 * arr[end] * cnt[arr[end]] + arr[end];
		cnt[arr[end]]++;
		end++;
	}
	
	while(R + 1 < end) {
		end--;
		ans = ans - 2 * arr[end] * cnt[arr[end]] + arr[end];
		cnt[arr[end]]--;
	}
}

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	
	int SQ_N = sqrt(N);
	
	for(int i = 0; i < Q; i++) {
		scanf("%d %d", &queries[i].left, &queries[i].right);
		queries[i].pos = i;
		queries[i].block = queries[i].left / SQ_N;
	}
	
	sort(queries, queries + Q, cmp);
	int beg = 1, end = 1;
	long long ans = 0;
	for(int i = 0; i < Q; i++) {
		int L = queries[i].left;
		int R = queries[i].right;
		if(beg < L) {
			moveLeftPointer(beg, L, arr, ans);
			moveRightPointer(end, R, arr, ans);
		} else {
			moveRightPointer(end, R, arr, ans);
			moveLeftPointer(beg, L, arr, ans);
		}
		output[queries[i].pos] = ans;
	}
	
	for(int i = 0; i < Q; i++) {
		printf("%I64d\n", output[i]);
	}
	
	return 0;
}
