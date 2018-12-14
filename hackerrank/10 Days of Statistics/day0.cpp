#include<bits/stdc++.h>
using namespace std;
int fre[100005];
int main() {
	int N, a[2505];
	scanf("%d", &N);
	double sum = 0;
	for(int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		fre[a[i]]++;
	}
	sort(a, a + N);
	printf("%.1lf\n", sum/N);
	double median;
	if(N % 2 == 1) {
		median = a[N/2];
	} else {
		median = (double)(a[N/2] + a[N/2 - 1]) / 2;
	}
	printf("%.1lf\n", median);
	
	int mod = 0;
	for(int i = 1; i < N; i++) {
		if(fre[i] > fre[mod]) {
			mod = i;
		}
	}
	printf("%d\n", a[mod]);
	return 0;
}
