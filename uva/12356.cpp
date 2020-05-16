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
#define SZ 100007
int lft[SZ];
int rght[SZ];

void solve() {
	
	int S,B;
	while(1) {
		
		cin>>S>>B;
		if(S == 0 && B == 0) 
			break;
		
		for(int i = 1; i <= S; i++) {
			lft[i] = i - 1;
			rght[i] = i + 1;
		}
		
		lft[1] = -1;
		lft[0] = -1;
		rght[S] = -1;
		rght[S+1] = -1;

		
		while(B--) {
			int L, R;
			cin>>L>>R;
			if(lft[L] != -1) {
				cout<<lft[L];
				rght[lft[L]] = rght[R];
			} else {
				cout<<"*";
			}
			
			if(rght[R] != -1) {
				cout<<' '<<rght[R]<<endl;
				lft[rght[R]] = lft[L];
			} else {
				cout<<" *"<<endl;
			}
//			cout<<"right buddy:"<<endl;
//			for(int i = 1; i <= S; i++) {
//				cout<<rght[i]<<' ';
//			}
//			cout<<endl;
		}
		cout<<"-"<<endl;
	}
}

int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
