#include<cstdio>
using namespace std;
int main(){
	int n, a[105];
	while(scanf("%d",&n) == 1){
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		long long ans = 1;
		int i;
		for(i = 0; a[i] != 1 && i < n; i++);
		
		if(i == n){
			printf("0\n");
			continue;
		}
		
		int cnt = 0;
		
		for(i++; i < n; i++){
			if(a[i] == 1){
				ans *= (cnt + 1);
				cnt = 0;
			}else{
				cnt++;
			}
		}
		
		printf("%I64d\n", ans);
	}
	return 0;
}
