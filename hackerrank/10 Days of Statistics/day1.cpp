#include<bits/stdc++.h>
using namespace std;
int main() {
	int N, x[55], w[55];
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &x[i]);
	}
	
	double up = 0, down = 0;
	for(int i = 0; i < N; i++) {
		scanf("%d", &w[i]);
		up += w[i] * x[i];
		down += w[i];
	}
	
	printf("%.1lf\n", up/down);
	
	return 0;
}
