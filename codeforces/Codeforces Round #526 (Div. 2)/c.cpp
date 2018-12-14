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
#define M 1000000007
const int inf=2000000000;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //int i,j,k,m,n,cas,tc,cnt,total,ans;
    char s[100005];
    int cnt[100005];
    while(gets(s))
    {
    	int len = strlen(s);
    	CLR(cnt);
    	int i;
    	int asum = 0;
    	int bsum = 0;
    	for(i = 0; i < len && s[i] != 'b'; i++) {
    		if(s[i] == 'a') {
    			cnt[i] = 1;
    			bsum++;
			}
		}
		for(i++; i < len; i++) {
			if(s[i] == 'a') {
				cnt[i] = (1 + bsum) % M;
				asum = (asum + cnt[i]) % M;
			} else if(s[i] == 'b') {
				bsum = (bsum + asum) % M;
				asum = 0;
			}
		}
		
		int ans = 0;
		for(int i = 0; i < len; i++) {
			ans = (ans + cnt[i]) % M;
		}
		printf("%d\n", ans);
    }
    return 0;
}


