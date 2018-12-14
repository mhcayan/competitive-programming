#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int N, ans[10];

bool canPlace(int i, int j){
	int y;
	for(int x = 1; x < i; x++){
		y = ans[x];
		if(j == y || (x - i == abs(y - j))){
			return false;
		}
	}
	return true;
}
void print(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(j == ans[i]){
				printf("Q");
			}else{
				printf("_");
			}
		}
		printf("\n");
	}
}
void solve(int i, int j){
	if(i > N || j > N){
		return;
	}
	if(canPlace(i, j)){
		ans[i] = j;
		if(i == N){
			print();
			return;
		}
		solve(i + 1, 1);
	}
	else{
		solve(i, j+1);
	}
}
int main()
{
	while(scanf("%d", &N) == 1)
	{
		solve(1,1);
	}
}

