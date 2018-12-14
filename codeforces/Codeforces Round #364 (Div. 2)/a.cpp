#include<cstdio>
using namespace std;
int main(){
	int n, a[105];
	while(scanf("%d", &n) == 1){
		int sum = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			sum += a[i];
		}
		int pair_sum = (sum * 2) / n;
//		printf("%d\n",pair_sum);
		int m = n/2;
		for(int i = 1; i <= n; i++){
			if(a[i] == 0){
				continue;
			}
			for(int j = i + 1; j <= n; j++){
				if(a[j] != 0 && a[j] + a[i] == pair_sum){
					printf("%d %d\n", i, j);
					a[j] = 0;
					a[i] = 0;
				}
			}
		}
	}
	return 0;
}
