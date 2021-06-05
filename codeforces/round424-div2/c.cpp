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
#define SZ 10005
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int k,n;
    cin>>k>>n;
    int a, b[2005];
    unordered_set<int>ss;
    int cum_a = 0;
    for(int i = 0; i < k; i++) {
        cin>>a;
        cum_a += a;
        ss.insert(cum_a);
    }

    for(int i = 1; i <= n; i++) {
        cin>>b[i];
    }

    //set<int> ::iterator it;
    int cnt = 0;
    for(auto it = ss.begin(); it != ss.end(); it++) {
        int x = b[1] - (*it);
        bool flag = true;
        for(int i = 2; i <= n; i++) {
            if(ss.find(b[i] - x) != ss.end()) {

            } else {
                flag = false;
                break;
            }
        }
        if(flag)
            cnt++;

    }
    cout<<cnt<<endl;
    return 0;
}