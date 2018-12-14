#include<cstdio>
#include<cstring>
#include<vector>
#define M 65
using namespace std;
char str[M];
long long dp[M][M], dpIncL[M][M], dpIncR[M][M];
long long find(int i, int j);
long long findIncludingRight(int i, int j);
long long findIncludingLeft(int i, int j){
	if(i > j){
		return 0;
	}
	if(i == j){
		return 1;
	}
	if(dpIncL[i][j] > -1){
		return dpIncL[i][j];
	}
	if(str[i]  == str[j]){
		return dpIncL[i][j] = 1 + find(i + 1, j - 1) + findIncludingLeft(i, j - 1);
	}else{
		return dpIncL[i][j] = findIncludingLeft(i, j -1);
	}
}

long long findIncludingRight(int i, int j){
	if(i > j){
		return 0;
	}
	if(i == j){
		return 1;
	}
	if(dpIncR[i][j] > -1){
		return dpIncR[i][j];
	}
	if(str[i]  == str[j]){
		return dpIncR[i][j] = 1 + find(i + 1, j - 1) + findIncludingRight(i + 1, j);
	}else{
		return dpIncR[i][j] = findIncludingRight(i + 1, j);
	}
}

long long find(int i, int j){
    if(i > j){
		return 0;
	}
	if(i == j){
		return 1;
	}
	if(dp[i][j] > -1){
		return dp[i][j];
	}
	if(str[i]  == str[j]){
		return dp[i][j] = 1 + find(i + 1, j - 1) * 2 + findIncludingRight(i + 1, j) + findIncludingLeft(i, j - 1);
	}else{
		return dp[i][j] = findIncludingRight(i + 1, j) + findIncludingLeft(i , j - 1) + find(i + 1, j - 1);
	}
}

int main(){
	int cas, tc = 1;
	scanf("%d", &cas);
	while(cas--){
		scanf("%s", str);
		
		memset(dp, -1, sizeof(dp));
		memset(dpIncR, -1, sizeof(dpIncR));
		memset(dpIncL, -1, sizeof(dpIncL));
		
		printf("Case %d: %lld\n", tc++, find(0, strlen(str) - 1));
	}
}
