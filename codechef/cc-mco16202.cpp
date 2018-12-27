//https://www.codechef.com/problems/MCO16202
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iterator>
#include<set>
#include<sstream>
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
#define M 1000000007
#define endl '\n'
const int inf=2000000000;
int dp[3002][2][3002];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    
    if(s[0] == '0' || s[0] == '?') {
    	dp[0][0][1] = 1;
	}
	
	if(s[0] == '1' || s[0] == '?') {
		dp[0][1][1] = 1;
	}

	for(int i = 1; i < s.size(); i++) {
		if(s[i] == '0' || s[i] == '?') {
			for(int j = 1; j <= i; j++) {
				if(dp[i-1][0][j] > 0) {
					dp[i][0][j] = (dp[i][0][j] + dp[i-1][0][j]) % M;
				}
				if(dp[i-1][1][j] > 0) {
					dp[i][0][j+1] = (dp[i][0][j+1] + dp[i-1][1][j] ) % M;
				}
			}
		}
		if(s[i] == '1' || s[i] == '?') {
			for(int j = 1; j <= i; j++) {
				if(dp[i-1][0][j] > 0) {
					dp[i][1][j+1] = (dp[i][1][j+1] + dp[i-1][0][j]) % M;
				}
				if(dp[i-1][1][j] > 0) {
					dp[i][1][j] = (dp[i][1][j] + dp[i-1][1][j]) % M;
				}
			}
		}		
	}
	
	for(int i = 1; i <= s.size(); i++) {
		cout<<(dp[s.size() - 1][0][i] + dp[s.size() - 1][1][i]) % M << ' ';
	}
	cout<<endl;
    return 0;
}

