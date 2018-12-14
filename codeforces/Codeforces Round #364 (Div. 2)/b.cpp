#include<cstdio>
#include<vector>
using namespace std;
#define MX 100001
#define LL long long
bool row[MX], col[MX];
LL rowCount, colCount;
vector<LL> ans;
int main(){
	LL i, n, m, x, y;
	scanf("%I64d %I64d", &n, &m);
	for(i = 0; i < m; i++){
		scanf("%I64d %I64d", &x, &y);
		if(!row[x]){
			row[x] = true;
			rowCount++;
		}
		if(!col[y]){
			col[y] = true;
			colCount++;
		}
		ans.push_back(n * n - (rowCount + colCount) * n + rowCount * colCount);
	}
	
	for(i = 0; i < m; i++){
		printf("%I64d ", ans[i]);
	}
	printf("\n");
	return 0;
}
