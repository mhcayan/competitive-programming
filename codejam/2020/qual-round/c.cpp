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
#define piii pair<pii,int>
#define psi pair<string,int>
#define eps 1e-11
#define mod 100000007
#define endl '\n'
const int inf=2000000000;
#define SZ 105
struct task {
	int start, end, loc, ans;
};

bool cmp1(const task &a, const task &b) {
	if(a.start == b.start)
		return a.end < b.end;
	return a.start < b.start;
}

bool cmp2(const task &a, const task &b) {
	return a.loc < b.loc;
}


int main() {
	
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cas, n;
    cin>>cas;
    vector<task> v;
    for(int tc = 1; tc <= cas; tc++) {
    	v.clear();
    	int end[2] = {0,0};
		cin>>n;
    	for(int i = 0; i < n;i++) {
    		task x;
    		cin>>x.start>>x.end;
    		x.loc = i;
    		v.pb(x);
		}
		
		sort(v.begin(), v.end(), cmp1);
		
		bool impossible = false;
		for(int i = 0; i < v.size(); i++) {
			if(end[0] <= v[i].start) {
				v[i].ans = 0;
				end[0] = v[i].end;
			} else if(end[1] <= v[i].start) {
				v[i].ans = 1;
				end[1] = v[i].end;
			} else {
				impossible = true;
				break;
			}
		}
		
		sort(v.begin(), v.end(), cmp2);
		cout<<"Case #"<<tc<<": ";
		if(impossible) {
			cout<<"IMPOSSIBLE"<<endl;
		} else {
			for (int i = 0; i < n; i++) {
				if(v[i].ans) {
					cout<<"J";
				} else {
					cout<<"C";
				}
			}
			cout<<endl;
		}
	}	
    return 0;
}
