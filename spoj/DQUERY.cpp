#include<bits/stdc++.h>
using namespace std;
#define SIZE 30005
#define MAX_VALUE 1000000
int cnt[MAX_VALUE + 5];
struct Query{
	int left;
	int right;
	int block;
	int serial;
	int ans;
};

bool cmp(Query a, Query b) {
	if(a.block == b.block) {
		return a.right < b.right;
	}
	return a.block < b.block;
}

bool cmp2(Query a, Query b) {
	return a.serial < b.serial;
}
Query queries[200005];

int main(){
	int N, Q, data[SIZE], beg = 1, end = 1;
	scanf("%d", &N);
	int SQN = sqrt(N);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &data[i]);
	}
	
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		scanf("%d", &queries[i].left);
		scanf("%d", &queries[i].right);
		queries[i].block = queries[i].left / SQN;
		queries[i].serial = i;
	}
	
	sort(queries, queries + Q, cmp);
	int ans = 0;
	for(int i = 0; i < Q; i++) {
		int L = queries[i].left;
		int R = queries[i].right;
		while(beg < L) {
			cnt[data[beg]]--;
			if(cnt[data[beg]] == 0) {
				ans--;
			}
			beg++;
		}
		
		while(beg > L) {
			beg--;
			cnt[data[beg]]++;
			if(cnt[data[beg]] == 1) {
				ans++;
			}
		}
		
		while(end <= R) {
			cnt[data[end]]++;
			if(cnt[data[end]] == 1) {
				ans++;
			}
			end++;
		}
		
		while(end > R + 1) {
			end--;
			cnt[data[end]]--;
			if(cnt[data[end]] == 0) {
				ans--;
			}
		}
		queries[i].ans = ans;
//		printf("L = %d R = %d\n", L, R);
//		printf("beg = %d end = %d\n",beg, end);
//		for(int j = 1; j <=4; j++) {
//			printf("count[%d]= %d\n", j, cnt[j]);
//		}
	}
	sort(queries, queries + Q, cmp2);
	
	for(int i = 0; i < Q; i++) {
		printf("%d\n", queries[i].ans);
	}
	return 0;
}
