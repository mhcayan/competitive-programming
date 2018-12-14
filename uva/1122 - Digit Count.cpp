#include<cstdio>
using namespace std;
int a[12], n;
int find(int beg, int m){
	if(m == 0){
		return 1;
	}
	int ans = 0;
	for(int i = beg; i <= n; i++){
		if(a[i] - a[beg] < 3){
			ans += find(i, m - 1);
		}
	}
	return ans;
}
int main(){
	int cas, tc, i, m;
	scanf("%d", &cas);
	for(tc = 1; tc <= cas; tc++){
		scanf("%d %d", &n, &m);
		for(i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		printf("%d\n", find(1, m));
	}
	return 0;
}
