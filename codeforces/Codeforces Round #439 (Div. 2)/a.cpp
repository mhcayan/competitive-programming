#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, a[5000], b[5000];
	while(scanf("%d", &n) == 1) {
		
		set<int> ss;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			ss.insert(a[i]);
		}
		
		for(int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
			ss.insert(b[i]);
		}
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(ss.find(a[i] ^ b[j]) != ss.end()) {
					cnt++;
				}
			}
		}
//		printf("%d", cnt);
		if(cnt % 2 == 0) {
			printf("Karen\n");
		} else {
			printf("Koyomi\n");
		}
		
		
	}
}
