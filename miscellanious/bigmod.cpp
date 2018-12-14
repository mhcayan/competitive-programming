#include<cstdio>
#include<ctime>
using namespace std;
long long bigmod(long long a, long long b, long long c){
	if(b == 0){
		return 1;
	}
	if(b%2 == 0){
		long long temp = bigmod(a, b/2, c) % c;
		return (temp * temp) % c;
	}
	else{
		return (a  * bigmod(a, b-1, c)) % c;
	}
}

long long fastbigmod(long long a, long long b, long long c){
	int ans = 1;
	while(b){
		if(b & 1){
			ans = (ans * a) % c;
		}
		a = (a * a) % c;
		b = b >> 1;
	}
	return ans;
}
int main(){
	freopen("input.txt", "r", stdin);
	long long a, b, c;
	clock_t t1 = 0;
	clock_t t2 = 0;
	while(scanf("%lld %lld %lld",&a, &b, & c) == 3){
//		printf("%lld %lld %lld\n", a, b, c);
        clock_t start = clock();
		bigmod(a % c,b % c,c);
		t1 = t1 + clock() - start;
		
		clock_t start2 = clock();
		fastbigmod(a % c,b % c,c);
		t2 = t2 + clock() - start2;
	}
	printf("%ld %ld\n", t1, t2);
	printf("t1 = %.2lf seconds\n", (double)t1 /CLOCKS_PER_SEC);
	printf("t2 = %.2lf seconds\n", t1 /CLOCKS_PER_SEC);
	return 0;
}
