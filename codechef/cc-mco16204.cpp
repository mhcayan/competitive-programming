//https://www.codechef.com/problems/MCO16204
#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL inf=2000000000000000LL;
#define ULL unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-inf,sizeof(a))
#define ff first
#define ss second
//#define pii pair<int,int>
#define pll pair<LL,LL>
#define psi pair<string,int>
#define eps 1e-11
#define mod 100000007
#define endl '\n'
#define MXN 5003
pll dp[MXN][MXN][2];
bool mem[MXN][MXN][2];
int N, a[MXN], b[MXN];
pll find(int i, int j, int cur) {

	if(i == N && j == N) {
		return pll(0,0);
	}
	
	if(mem[i][j][cur]) {
		return dp[i][j][cur];
	}
	mem[i][j][cur] = true;
    int next = cur ^ 1;	
	if(i==N) {
		pll aa = find(i, j+1, next);
		if(cur && 1) {
			dp[i][j][cur].ff = aa.ff;
			dp[i][j][cur].ss = b[j] + aa.ss;
		} else {
			dp[i][j][cur].ff = b[j] + aa.ff;
			dp[i][j][cur].ss = aa.ss;
		}
	} else if(j == N) {
		pll aa = find(i+1, j, next);
		if(cur && 1) {
			dp[i][j][cur].ff = aa.ff;
			dp[i][j][cur].ss = a[i] + aa.ss;
		} else {
			dp[i][j][cur].ff = a[i] + aa.ff;
			dp[i][j][cur].ss = aa.ss;
		}
	} else {
		pll take1 = find(i+1, j, next);
		pll take2 = find(i, j+1, next);
		if(cur && 1) {
			if(a[i] + take1.ss > b[j] + take2.ss) {
				dp[i][j][cur].ff = take1.ff;
				dp[i][j][cur].ss = a[i] + take1.ss;
				
			} else {
				dp[i][j][cur].ff = take2.ff;
				dp[i][j][cur].ss = b[j] + take2.ss;
			}		
		}
		else {
			if(a[i] + take1.ff > b[j] + take2.ff) {
				dp[i][j][cur].ff = a[i] + take1.ff;
				dp[i][j][cur].ss = take1.ss;
			} else {
				dp[i][j][cur].ff = b[j] + take2.ff;
				dp[i][j][cur].ss = take2.ss;
			}
		}
	}
	return dp[i][j][cur];
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i = 0; i < N; i++) {
    	cin>>a[i];
	}
	for(int i = 0; i < N; i++) {
		cin>>b[i];
	}
	pll ans = find(0, 0, 0);
	cout<<ans.ff - ans.ss;
	return 0;
}
