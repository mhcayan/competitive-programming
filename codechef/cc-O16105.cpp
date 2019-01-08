//https://www.codechef.com/problems/MCO16105
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

int dp[40002];
int cnt[32][40002];

int bs(int b, int e, int c) {
	while(b<=e) {
		int mid = (b + e) / 2;
		if(dp[mid] < c) {
			b = mid + 1;
		} else {
			e = mid - 1;
		}
	}
	return b;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int m, n;
	string str[32];
	cin>>m>>n;
	
	for(int i = 0; i < m; i++) {
		cin>>str[i];
	}
	
	int l, r;
	cin>>l>>r;
	//cnt[i][j] = number of one's in column j from row 0 to i. It will be used to calculate dp
	for(int j = 0; j < n; j++) {
		cnt[0][j] = str[0][j] - '0';
		for(int i = 1; i < m; i++) {
			cnt[i][j] = cnt[i-1][j] + str[i][j] - '0';
		}
	}
	//dp contains the cumulative sum of 1's in subrectangle i to j
	int ans = 0;
	for(int i = 0; i < m; i++) {
		for(int j = i; j < m; j++) {
			dp[0] = i > 0 ? cnt[j][0] - cnt[i-1][0]: cnt[j][0];
			for(int k = 1; k < n; k++) {
				dp[k] = dp[k-1] + cnt[j][k] - (i > 0 ? cnt[i-1][k] : 0);
			}
			for(int k = 0; k < n; k++) {
				int baadone = k > 0 ? dp[k-1] : 0;
				int f1 = bs(k, n - 1, l + baadone);
				int f2 = bs(k, n - 1, r + 1 + baadone);
				ans+= f2 - f1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
