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
    long long i,j,h,total;
    char str[1000006],hv[]="heavy",mt[]="metal";
    while(scanf("%s",str)==1)
    {
    	total=0;
    	h=0;
    	for(i=0;str[i];i++)
    	{
    	    if(str[i]=='h')	
    	    {
    	    	for(j=1;hv[j];j++)
    	    	{
    	    		if(str[i+j]!=hv[j])
    	    		    break;
    	    	}
    	    	if(!hv[j])
    	    	{
    	    		h++;
    	    		i=i+j-1;
    	    	}
    	    }
    	    else if(str[i]=='m')
    	    {
    	    	for(j=1;mt[j];j++)
    	    	{
    	    		if(str[i+j]!=mt[j])
    	    		    break;
    	    	}
    	    	if(!mt[j])
    	    	{
    	    		total+=h;
    	    		i=i+j-1;
    	    	}
    	    }
    	}
    	printf("%I64d\n",total);
    }
    return 0;
}

