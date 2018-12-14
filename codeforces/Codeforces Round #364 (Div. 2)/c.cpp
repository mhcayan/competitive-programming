#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
int cnt[500];
int main(){
	int len, n, i, unique, beg, end, ans;
	char str[100009];
	while(scanf("%d", &n) == 1){
		memset(cnt, 0, sizeof(cnt));
		scanf("%s", str);
		unique = 0;
		for(i = 0; i < n; i++){
			if(cnt[str[i]] == 0){
				unique++;
				cnt[str[i]] = 1;
			}
		}
		memset(cnt, 0, sizeof(cnt));
		int un = 0;
		for(i = 0; i < n; i++){
			if(cnt[str[i]] == 0){
				un++;
				if(un == unique){
					break;
				}
			}
			cnt[str[i]]++;
		}
		beg = 0;
		end = i;
		ans = end + 1;
		printf("%d %d\n", beg, end);
		while(beg < n){
			if(cnt[str[beg]] == 1){
				char ch = str[beg];
				end++;
				while(end < n){
					if(str[end] == ch){
//						ans = max(ans, end - beg);
						break;
					}else{
						end++;
					}
				}
				if(end == n){
					break;
				}
			}
			else{
				cnt[str[beg]]--;
				ans = min(ans, end - beg);
			}
			beg++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
