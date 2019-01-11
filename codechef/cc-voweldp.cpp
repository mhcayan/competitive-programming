//https://www.codechef.com/problems/VOWELDP
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
#define mod 1000000007
#define endl '\n'
const int inf=2000000000;
int getIndex(char ch) {
	switch(ch) {
		case 'a': return 0;
		case 'e': return 1;
		case 'i': return 2;
		case 'o': return 3;
		case 'u': return 4;
	}
	return -1;
}

LL dp[102][102];
LL find(int n, int m) {
	if(n == 0) {
		return 1;
	}
	if(m == 0) {
		return 0;
	}
	if(dp[n][m] > -1) {
		return dp[n][m];
	}
	LL ans = 0;
	for(int i = 0; i <= n; i++) {
		ans = (ans + find(i, m - 1)) % mod;
	}
	dp[n][m] = ans;
	return dp[n][m];
}
int main() {
	int cnt[5];
	int given[5];
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int cas;
	SET(dp);
	cin>>cas;
	string str;
	while(cas--) {
		CLR(given);
		CLR(cnt);
		for(int i = 0; i < 5; i++) {
			cin >> cnt[i];
		}
		cin >> str;
		for(int i = 0; i < str.size(); i++) {
			int indx = getIndex(str[i]);
			if(indx >= 0) {
				given[indx]++;
			}
		}
		
		LL ans = 1;
		for(int i = 0; i < 5; i++) {
			if(given[i] > 0) {
				// cnt[i] - given[i] = number of extra vowels of type i
				// given[i]=number of slots of type i
				ans = (ans * find(cnt[i] - given[i], given[i])) % mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
