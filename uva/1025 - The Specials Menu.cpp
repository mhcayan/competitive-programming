#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct data{
	int m;
	int n;
};
int main()
{
	int cas, tc = 1, i, j, k, l, len;
	char str[65];
	vector<data> v[62];
	scanf("%d",&cas);
	while(cas--){
		scanf("%s",str);
		len = strlen(str);
		for(i = 0; i < len; i++){
			data d;
			d.m = i;
			d.n = i;
			v[1].push_back(d);
		}
		
		for(i = 0; i < len; i++){
			for(j = i + 1; j < len; j++){
				if(str[i] == str[j]){
					data d;
					d.m = i;
					d.n = j;
					v[2].push_back(d);
				}
			}
		}
		
		for(i = 3; i <= len; i++){
			l = i - 2;
			for(j = 0; j < v[l].size(); j++){
				for(k = 0; k < v[2].size(); k++){
					if(v[2][k].m < v[l][j].m && v[l][j].n < v[2][k].n){
						v[i].push_back(v[2][k]);
					}
				}
			}
		}
		int ans = 0;
		for(i = 1; i <= len; i++){
			ans += v[i].size();
			v[i].clear();
		}
		printf("Case %d: %d\n", tc++, ans);
	}
	return 0;
}
