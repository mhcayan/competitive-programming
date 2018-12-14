#include<stdio.h>
#include<string.h>
long long dp[65][65];
char str[65];
long long find(int i, int j){
	if(i > j){
		return 0;
	}
	if(i == j){
		return 1;
	}
	if(str[i] == str[j]){
		return dp[i][j] = 1 + find(i + 1, j) + find(i, j - 1);
	} else{
		return dp[i][j] = find(i + 1, j) + find(i , j - 1) - find(i + 1, j - 1);
	}
	return dp[i][j];
}
int main(){
	int cas, tc = 1;
	scanf("%d", &cas);
	while(cas--){
		scanf("%s", str);
		memset(dp, -1, sizeof(dp));
		printf("Case %d: %lld\n", tc++, find(0, strlen(str) - 1));
	}
}
