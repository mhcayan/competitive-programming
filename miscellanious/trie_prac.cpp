#include<cstdio>
#include<cstring>
using namespace std;
struct node{
	int value;
	int next[30];
};
node data[500];
int mx = 1;

void add(char *str){
	int len = strlen(str);
	int cur = 0;
	for(int i = 0; i < len; i++){
		if(data[cur].next[str[i] - 'a'] == 0) {
			data[cur].next[str[i] - 'a'] = mx++;
		}
		cur = data[cur].next[str[i] - 'a'];
	}
	data[cur].value = 1;
}
bool found(char *str){
	int cur = 0;
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(data[cur].next[str[i] - 'a'] == 0){
			return false;
		}
		cur = data[cur].next[str[i] - 'a'];
	}
	if(data[cur].value == 1)
		return true;
    return false;
}
int main(){
	int n, q;
	char str[100];
	while(scanf("%d", &n) == 1){
		for(int i = 0; i < n; i++){
			scanf("%s",str);
			add(str);
		}
		scanf("%d", &q);
		while(q--){
			scanf("%s", str);
			if(found(str)){
				printf("--yes");
			}else{
				printf("--no");
			}
			printf("\n");
		}
	}
}
