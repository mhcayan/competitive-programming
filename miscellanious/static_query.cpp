#include<cstdio>
#include<algorithm>
using namespace std;
const int n = 5;
const int s = 2;
int arr[] = {-1, 10, 8, 5, 11, 7};
int lookup[n + 1][s+1];
int maxl[n + 1];
int main(){
	
	for(int i = 1; i <= n; i++) {
		lookup[i][0] = arr[i];
	}
	printf("\n");
	for(int l = 1; l <= s; l++) {
		for(int i = 1; i <= n; i++) {
			lookup[i][l] = max(lookup[i][l - 1], lookup[i + (1 << (l - 1))][l - 1]);
		}
	}
	
	for(int l = 0; l <= s; l++) {
		for(int i = 1; i <= n; i++){
			printf("%d ", lookup[i][l]);
		}
		printf("\n");
	}
	
	for(int i = 0; i <= s; i++){
		for(int j = 1 << i; j < 1 << (i + 1) && j <= n; j++) {
			maxl[j] = i;
		}
	}
	int x,y;
	while(scanf("%d %d", &x, &y) == 2) {
		int seg_len = y - x + 1;
		
		int l = maxl[seg_len];
		printf("%d\n", max(lookup[x][l], lookup[y - (1 << l) + 1][l]));
	}
	return 0;
}
