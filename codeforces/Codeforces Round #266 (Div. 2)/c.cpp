//https://codeforces.com/contest/466/problem/C
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define ff first
#define ss second
#define pii pair<int,int>
#define psi pair<string,int>
#define eps 1e-11
#define mod 100000007
#define endl '\n'
const int inf=2000000000;
#define SZ 500005
bool vis[SZ];
int P[SZ], D[SZ], L[SZ];
map<int, int> idByNode;
map<int, int> nodeById;
vector<int> edge[SZ];
vector<int> cost[SZ];
int par[SZ][16];
int dis[SZ][16];
int nodeCount = 0, N;

int a[SZ];
LL find(int n, LL total_sum) {
	
	if(total_sum %3) {
		return 0;
	}
	
	LL seg_sum = total_sum / 3;
	vector<int> left_index;
	
	LL sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		if(sum == seg_sum) {
			left_index.pb(i);
		}
	}
	
	if(left_index.empty()) return 0;
	
	LL ans = 0;
	sum = 0;
	int j = left_index.size() - 1;
	for(int i = n - 1; i >= 0; i--) {
		sum += a[i];
		if(sum == seg_sum) {
			while(left_index[j] >= i - 1) {
				j--;
				if(j < 0) {
					break;
				}
			}
			
			if(j < 0) {
				break;
			}
			
			ans += j + 1;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    LL sum = 0;
    for(int i = 0; i < n; i++) {
    	cin>>a[i];
    	sum += a[i];
	}
	
	cout<<find(n, sum)<<endl;
	
    return 0;
}
