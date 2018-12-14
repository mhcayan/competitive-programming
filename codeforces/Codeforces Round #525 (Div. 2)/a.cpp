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
const int inf=2000000000;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //int i,j,k,m,n,cas,tc,cnt,total,ans;
    int x;
    while(scanf("%d", &x) == 1)
    {
    	bool found = false;
    	for(int b = 1; b <= x; b++) {
    		for(int i = 1; b * i <= x; i++) {
    			int a = b *i;
    			if(a * b > x && i < x) {
    				printf("%d %d\n", a, b);
    				found = true;
    				break;
				}
			}
			if(found)
			    break;
		}
		if(!found) {
			printf("-1\n");
		}
    }
    return 0;
}

