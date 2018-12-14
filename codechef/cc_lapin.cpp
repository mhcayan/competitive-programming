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
    int cas,l,k,i;
    vector<char>s1,s2;
    char str[1009];
    scanf("%d",&cas);
    while(cas--)
    {
    	scanf("%s",str);
    	l=strlen(str);
    	k=l/2;
    	for(i=0;i<k;i++)
    	{
    		s1.pb(str[i]);
    		s2.pb(str[l-1-i]);
    	}
    	sort(s1.begin(),s1.end());
    	sort(s2.begin(),s2.end());
    	for(i=0;i<k;i++)
    	  if(s1[i]!=s2[i])
    	      break;
    	if(i<k)
    	   printf("NO\n");
    	else
    	   printf("YES\n");
    	s1.clear();
    	s2.clear();
    }
    return 0;
}

