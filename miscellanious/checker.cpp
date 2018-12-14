#include<stdio.h>
int main()
{
    int cas,v,ar[10000],i;
    freopen("output_improved2.txt","r",stdin); 
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    scanf("%d",&ar[i]);
    freopen("output_dp2.txt","r",stdin);
    scanf("%d",&cas);
    freopen("check.txt","w",stdout);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&v);
        if(v!=ar[i])
        {
            printf("failed at case %d\n",i);
            return 0;
        }
    }
    printf("passed\n");
    return 0;
}
