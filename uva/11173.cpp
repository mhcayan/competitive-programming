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
#define SZ 100005

int find(int n, int k) {

	vector<int> ans;
	for(int i = n; i > 1; i--) {
		
		if(k >= 1 << (i-1)) {
			ans.pb(1);
			k = (1 << i) -1 - k;
		} else {
			ans.pb(0);
		}
	}
	
	ans.pb(k);
	int value = 0;
	//for(auto x : ans) cout<<x<<' ';
	//cout<<endl;
	for(int i = ans.size() - 1; i >= 0; i--) {
		
		if(ans[i]) {
			value += (1 << (ans.size() - 1 - i));
		}
	}
	return value;
}

void solve() {
	int n, k;
	cin>>n>>k;
	cout<<find(n,k)<<endl;
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(NULL);
	int cas; cin>>cas; while(cas--) solve();
    return 0;
}

