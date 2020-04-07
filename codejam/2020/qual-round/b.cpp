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
inline int digit(char i) {
	return i - '0';
}
int main() {
	
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cas, n;
    cin>>cas;
    string str;
    int lp_count[SZ];
    int rp_count[SZ];
    int depth[SZ];
    for(int tc = 1; tc <= cas; tc++) {
    	
		cin>>str;
    	for(int i = 0; str[i];i++) {
    		lp_count[i] = 0;
    		rp_count[i] = 0;
    		depth[i] = 0;
		}
		
		for(int i = 0; str[i]; i++) {
			while(depth[i] < digit(str[i])) {
				lp_count[i]++;
				int j = i;
				while(str[j] && depth[j] < digit(str[j])) {
					depth[j]++;
					j++;
				}
				rp_count[j-1]++;
			}
		}
		cout<<"Case #" << tc<<": ";
		for(int i = 0; str[i]; i++) {
			for(int j = 0; j < lp_count[i]; j++) {
				cout<<'(';
			}
			cout<<str[i];
			for(int j = 0; j < rp_count[i]; j++) {
				cout<<')';
			}
		}
		cout<<endl;
		
	}	
    return 0;
}
