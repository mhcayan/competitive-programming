#include<stdio.h>
int dp[10005],pr[10000];
bool f[10005];
int main()
{
    int i,j,k,sum,n;
    pr[0]=2;
    k=1;
    for(i=3;i<=100;i+=2)
    {
        if(f[i]==0)
        {
            pr[k++]=i;
            for(j=i*i;j<=10000;j+=i+i)
               f[j]=1;
        }
    }
    for(;i<=10000;i+=2)
        if(f[i]==0)
            pr[k++]=i;
    for(i=0;i<k;i++)
    {
        sum=pr[i];
        dp[sum]++;
        for(j=i+1;j<k;j++)
        {
            sum+=pr[j];
            if(sum>10000)
                break;
            dp[sum]++;
        }
    }
    while(scanf("%d",&n)&&n)
        printf("%d\n",dp[n]);
    return 0;
}
