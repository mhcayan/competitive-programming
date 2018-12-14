#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define CLR(a) memset(a,0,sizeof(a))
int T[100900][12],S[100900];
int main()
{
    int cas,tc,i,n,r,d,total;
    bool flag;
    char str[13];
    scanf("%d",&cas);
    for(tc=1;tc<=cas;tc++)
    {
        scanf("%d",&n);
        flag=0;
        total=0;
        CLR(T);
        CLR(S);
        while(n--)
        {
            scanf("%s",str);
            if(flag)
                continue;
            r=0;
            for(i=0;str[i];i++)
            {
                d=str[i]-'0';
                if(T[r][d]==0)
                {
                    T[r][d]=++total;
                }
                r=T[r][d];
                if(S[r])
                {
                    flag=1;
                    break;
                }
            }
            S[r]=1;
            for(i=0;i<10;i++)
            {
                if(T[r][i])
                {
                    flag=1;
                    break;
               }
            }              
        }
        if(flag)
            printf("Case %d: NO\n",tc);
        else 
            printf("Case %d: YES\n",tc);
    }
    return 0;
}
