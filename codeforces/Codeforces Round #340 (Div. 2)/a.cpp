#include<cstdio>
using namespace std;
int main(){
	int x;
	while(scanf("%d",&x) == 1){
		if(x % 5 == 0){
			printf("%d\n", x/5);
		}
		else{
			printf("%d\n", x/5 + 1);
		}
	}
	return 0;
}
