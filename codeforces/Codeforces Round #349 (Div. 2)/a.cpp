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
#define big long long
#define ubig unsigned long long
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
    int i,j,k,m,n,cas,tc,cnt,total,ans, d, h, v, e;
    while(scanf("%d %d %d %d", &d, &h, &v, &e) == 4)
    {
    	double dec = (pi * d * d * e) / 4;
    	if(dec >= v){
    		printf("NO\n");
		}else{
		    double area = (pi * d * d * h)/4;
		    printf("YES\n%lf\n", area/(v-dec));
		}
    	
    	
    }
    return 0;
}

