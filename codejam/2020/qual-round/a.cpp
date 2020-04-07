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
#define SZ 105
int a[SZ][SZ];
int main() {
	
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cas, n;
    cin>>cas;
    for(int tc = 1; tc <= cas; tc++) {
    	cin>>n;
    	int trace = 0, row = 0, col = 0;
    	for(int i = 0; i < n; i++) {
    		set<int> ss;
    		for(int j = 0; j < n; j++) {
    			int v;
    			cin>>v;
    			if(j == i) trace += v;
    			
    			ss.insert(v);
    			a[i][j] = v;
			}
			if(ss.size() != n) {
				row++;
			}
		}
		
		for(int j = 0; j < n; j++) {
			set<int>ss;
			for(int i = 0; i < n; i++) {
				ss.insert(a[i][j]);
			}
			if(ss.size() != n) {
				col++;
			}
		}
		cout<<"Case #" << tc<<": "<<trace<<' '<<row<<' '<<col<<endl;
		
	}	
    return 0;
}
