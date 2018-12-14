#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,a,n) for(int i=(a);i<(n);i++)
#define dec(i,n) for(int i=(n);i>0;i--)
#define decc(i,a,n) for(int i=(a);i>(n);i--)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))
#define mem(a,b) memset((a),(b),sizeof(a))
#define clr(a) mem(a,0)
const double pi=acos(-1.0);
const int inf=10000000;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef vector< string > VS;
typedef vector< ll > VLL;
#define eps 1e-9
//main code starts here
#define max 1505
char s[max],good[max];
struct info
{
    //bool num;
    int next[26];
}arr[max*max];
int tot;
int main()
{
    int k;
    scanf("%s",s);
    scanf("%s",good);
    scanf("%d",&k);
    rep(i,26)good[i]-='0';
    rep(j,26)arr[0].next[j]=-1;
    int ans=0;
    int cou;
    tot=0;
    int n=strlen(s);
    //rep(i,26) printf("%d\n",good[i]);
    rep(i,n)
    {
        cou=0;
        int id=0;
        repp(j,i,n)
        {
            if(!good[s[j]-'a']) cou++;
            if(cou>k) break;
            //puts("ok");
            int ch=s[j]-'a';
            if(arr[id].next[ch]==-1)
            {
                tot++;
                ans++;
                arr[id].next[ch]=tot;
                //arr[tot].num=0;
                rep(i,26) arr[tot].next[i]=-1;
            }
            int ne=arr[id].next[ch];
            id=ne;
        }
    }
    printf("%d\n",ans);
	return 0;
}
