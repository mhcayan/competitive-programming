#include<cstdio>
#include<set>
using namespace std;
int main(){
	int a[5], v, n;
	while(scanf("%d", &n) == 1){
		set<int>ss;
		set<int>::iterator it;
		for(int i = 0; i < n; i++){
			scanf("%d", &v);
			ss.insert(v);
		}
		if(ss.size() > 3){
			printf("NO\n");
		}else{
			if(ss.size() == 2){
				printf("YES\n");
			}else if(ss.size() == 3){
				int i = 0;
				for(it = ss.begin(); it != ss.end(); it++){
					a[i++] = *it;
				}
				if(a[1] - a[0] == a[2] - a[1]){
					printf("YES\n");
				}else{
					printf("NO\n");
				}
			}else{
				printf("YES\n");
			}
		}
	}
	return 0;
}
