#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	long long l1, l2, r1, r2, u, l, x, k;
	while(scanf("%I64d %I64d %I64d %I64d %I64d", &l1, &r1, &l2, &r2, &k) == 5){
		l = max(l1, l2);
		u = min(r1, r2);
		if(u < l){
			printf("0\n");
		}else{
			if(l <= k && k <= u){
				x = 1;
			}else{
				x = 0;
			}
			printf("%I64d\n", u - l + 1 - x);
		}
	}
	return 0;
}
