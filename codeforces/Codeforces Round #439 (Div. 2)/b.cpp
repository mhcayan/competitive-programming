#include<bits/stdc++.h>
using namespace std;

int main() {
	long long a,b;
	while(scanf("%I64d %I64d", &a, &b) == 2) {
		long long ans = 1;
		for(long long x = a + 1; x <= b; x++) {
			ans = (ans * (x % 10)) % 10;
			if(ans == 0) {
				break;
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
