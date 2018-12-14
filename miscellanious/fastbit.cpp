#include<stdio.h>
#define M (1 << 16) - 1
unsigned long long dp[M + 2];

void preCal(){
	int i, j;
	for(i = 1; i <= M; i++){
		dp[i] = dp[i-1];
		for(j = 0; j < 15; j++){
			if((i & (1 << j)) && (i & (1 << (j + 1)))){
				dp[i]++;
			}
		}
	}
}
unsigned int no_of_pair(int i){
	unsigned int cnt = 0, j;
	for(j = 0; j < 15; j++){
		if((i & (1 << j)) && (i & (1 << (j + 1)))){
			cnt++;
		}		
	}
	return cnt;
}
int main(){
	unsigned int cas, tc = 1, n, mn, mx, odd;
	unsigned long long ans;
	preCal();
	scanf("%u", &cas);
	while(cas--){
		scanf("%u", &n);
		mx = n >> 16;
		mn = n & ((1 << 16) - 1);
		if(mx == 0){
			ans = dp[mn];
		}else{
			ans = mx * dp[M] + dp[mx - 1] * (1 << 16);
            odd = mx / 2;
			ans += odd * (1 << 15) + no_of_pair(mx) * (mn + 1) + dp[mn];
			if((mx & 1) && ((mn >> 15) & 1)){
				ans += (mn ^ (1 << 15)) + 1;
			}
		}
		printf("Case %u: %llu\n", tc++, ans);
	}
	return 0;
}
