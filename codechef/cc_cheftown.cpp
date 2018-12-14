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
using namespace std;
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
int a[400010],cnt[400010];
int main()
{
	int n,w,i,ans;
	set<int>ss;
	set<int>::iterator b,e;
	while(scanf("%d %d",&n,&w)==2)
    {
		CLR(cnt);
		for(i=1;i<=w;i++)
		{
			scanf("%d",&a[i]);
			ss.insert(a[i]);
			cnt[a[i]]++;
		}
		b=ss.begin();
		e=ss.end();
		e--;
		ans=0;
		if(*e-*b+1==w && ss.size()==w)
			ans++;
		for(;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(cnt[a[i-w]]==1)
			{
				cnt[a[i-w]]=0;
			    ss.erase(a[i-w]);
			}
			else
				cnt[a[i-w]]--;
			ss.insert(a[i]);
			cnt[a[i]]++;
			b=ss.begin();
		    e=ss.end();
		    e--;
			if(*e-*b+1==w && ss.size()==w)
				ans++;
		}
		printf("%d\n",ans);
		ss.clear();
    }
    return 0;
}
