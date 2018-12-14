#include<bits/stdc++.h>
using namespace std;

struct node{
	int n, f;
};

vector<int> v;

bool cmp(node a, node b) {
	return a.n < b.n;
}

double getMedian(int i, int j) {
	int total = j - i + 1;
	if(total % 2 == 1) {
		return v[i + total / 2];
	} else {
		return (v[i + total / 2] + v[i + total / 2 - 1]) / 2;
	}
}

int main() {
	
	node data[100];
	int N;
	
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &data[i].n);
	}
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &data[i].f);
	}
	
	sort(data, data + N, cmp);
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < data[i].f; j++) {
			v.push_back(data[i].n);
		}
	}
	
	double q1, q3;
	q1 = getMedian(0, v.size() / 2 - 1);
	if(v.size() % 2 == 1) {
		q3 = getMedian(v.size() / 2, v.size() - 1);
	} else {
		q3 = getMedian(v.size() / 2 + 1, v.size() - 1);
	}
	printf("%.1lf\n", q3 - q1);	
	
	return 0;
}
