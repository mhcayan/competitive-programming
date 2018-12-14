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
int main()
{
    int cs,tc,i;
    double a,b,e,rat,l,w,angle,r,s;
    scanf("%d",&cs);
    for(tc=1;tc<=cs;tc++)
    {
        scanf("%lf : %lf",&a,&b);
        rat=a/b;
        b=0;
        e=400;
        for(i=0;i<10000;i++)
        {
            w=(b+e)/2;
            l=w*rat;
            angle=atan(l/w);
            angle=(90-angle)*2;
            r=sqrt(l*l+w*w)/2;
            s=(angle*pi*r)/180;
            if(s+l<200)
                b=w;
            else
                e=w;
        }
        printf("Case %d: %lf %lf\n",tc,l,w);
    }
    return 0;
}
