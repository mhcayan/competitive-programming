//https://www.codechef.com/problems/GOLDMINE
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

vector<vector<LL> > dp[32];

vector<vector<LL> > multiply (vector<vector<LL> > &mat, vector<vector<LL> > &mat2) {
	vector<vector<LL> > result(mat.size());
	for(int i = 0; i < mat.size(); i++) {
		for(int j = 0; j < mat2[0].size(); j++) {
			LL sum = 0;
			for(int k = 0; k < mat[0].size(); k++) {
				sum = (sum + (mat[i][k] * mat2[k][j]) % mod) % mod;
			}
			result[i].pb(sum);
		}
	}
	return result;
}

vector<vector<LL> > square (vector<vector<LL> > &mat) {
	return multiply(mat, mat);
}

void printMat(vector<vector<LL> > &mat) {
	for(int i = 0; i < mat.size(); i++) {
		for(int j = 0; j < mat[i].size(); j++) {
			cout<<mat[i][j] << ' ';
		}
		cout<<endl;
	}
}

void fillDp() {
	
	vector<vector<LL> > initMat;
	vector<LL> row1;
	row1.pb(0);
	row1.pb(1);
	row1.pb(1);
	vector<LL> row2;
	row2.pb(1);
	row2.pb(0);
	row2.pb(0);
	vector<LL> row3;
	row3.pb(0);
	row3.pb(1);
	row3.pb(0);
	
	initMat.pb(row1);
	initMat.pb(row2);
	initMat.pb(row3);
	
	dp[0] = initMat;
	for(int i = 1; i < 32; i++) {
		dp[i] = square(dp[i-1]);
	}
}

LL find(int n) {
	
	if(n < 2) return 0; //If n = 1; f(n) = 0
	if(n < 4) return 1; //If n = 2, 3; f(n) = 1
	
	n = n - 3;
	
	vector<vector<LL> > mat;
	vector<LL> row1;
	row1.pb(1);
	row1.pb(0);
	row1.pb(0);
	vector<LL> row2;
	row2.pb(0);
	row2.pb(1);
	row2.pb(0);
	vector<LL> row3;
	row3.pb(0);
	row3.pb(0);
	row3.pb(1);
	
	//push the identity matrix
	mat.pb(row1);
	mat.pb(row2);
	mat.pb(row3);
	
	//calculate M^K
	for(int i = 31; i >= 0; i--) {
		if(n & (1 << i)) {
			mat = multiply(mat, dp[i]);
		}
	}
//	printMat(mat);
	
	return (mat[0][0] + mat[0][1]) % mod;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    fillDp();
//    for(int i = 0; i < 5; i++) {
//    	cout<<"i = "<<i<<endl;
//    	printMat(dp[i]);
//    	cout<<endl;
//	}
	int cas;
	int n;
	cin>>cas;
	while(cas--) {
		cin>>n;
		cout<<find(n)<<endl;
	}
	return 0;
}
