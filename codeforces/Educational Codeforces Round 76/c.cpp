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
#define SZ 200005
int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int cas, n;
	cin>>cas;
	int a[SZ];
	map<int, vector<int> > mp;
	map<int, vector<int> >::iterator it;
	while(cas--) {
		cin>>n;
		for(int i = 0; i < n; i++) {
			cin>>a[i];
			if(mp.find(a[i]) == mp.end()) {
				vector<int> v;
				v.pb(i);
				mp[a[i]] = v;
			} else {
				mp[a[i]].pb(i);
			}
		}
		int mn = inf;
		for(it = mp.begin(); it != mp.end(); it++) {
			vector<int> v = it->ss;
			//sort(v.begin(), v.end());
			for(int i = 1; i < v.size(); i++) {
				if(v[i] - v[i-1] + 1 < mn) {
					mn = v[i] - v[i-1] + 1;
				}
			}
		}
		if(mn == inf) {
			cout<<"-1"<<endl;
		} else {
			cout<<mn<<endl;
		}
		mp.clear();
	}
	return 0;
}

