#include<cstdio>
using namespace std;
const int M = 32000;
int flag[M + 1];
int PRIME[10000];
int INDX = 0;
void sieve(){
	int i;
	PRIME[INDX++] = 2;
	for(i = 3; i * i <= M; i+=2){
		if(flag[i] == 0) {
			PRIME[INDX++] = i;
		    for(int j = i * i; j <= M; j+=i+i){
				flag[j] = 1;
		    }
		}
	}
	for(; i <= M; i+=2) {
		if(flag[i] == 0){
			PRIME[INDX++] = i;
		}
	}
}
int main(){
	sieve();
//	printf("%d\n", INDX);
	int t, l, r, x;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &l, &r);
		int range =  r - l;
		for(int i = 0; i <= range; i++) {
			flag[i] = 0;
		}
		for(int i = 0; i < INDX; i++) {
			if(l % PRIME[i] == 0) {
				x = l;
			}else{
				x = l - l % PRIME[i] + PRIME[i];
			}
			while(x <= r) {
				flag[x - l] = 1;
				x += PRIME[i];
			}
		}
		for(int i = 0; i <= range; i++) {
			if(flag[i] == 0) {
				printf("%d\n", l + i);
			}
		}
		if(t > 0) {
			printf("\n");
		}
	}
	return 0;
}
