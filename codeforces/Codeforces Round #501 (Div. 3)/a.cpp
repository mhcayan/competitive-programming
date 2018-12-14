#include<bits/stdc++.h>
#define M 1005
using namespace std;
int main() {
	int i, j, m, n, x, y;
	vector<pair<int, int> > segments;
	while(scanf("%d %d", &m, &n) == 2) {
		for(i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			segments.push_back(make_pair(x,y));
		}
		vector<int> ans;
		for(i = 1; i <= n; i++) {
			for(j = 0; j < m; j++) {
				if(segments[j].first <= i && i <= segments[j].second) {
					break;
				}
			}
			if(j == m) {
				ans.push_back(i);
			}
		}
		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		segments.clear();
	}
	return 0;
}
