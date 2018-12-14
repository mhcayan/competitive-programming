#include<stdio.h>
int main()
{
    int tc,g,s,n,q;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&g);
        while(g--)
        {
            scanf("%d %d %d",&s,&n,&q);
            if(n%2==0)
                printf("%d\n",n/2);
            else
            {
                if(s==1)
                {
                    if(q==1)
                        printf("%d\n",n/2);
                    else
                        printf("%d\n",n/2+1);
                }
                else
                {
                    if(q==2)
                        printf("%d\n",n/2);
                    else
                        printf("%d\n",n/2+1);
                }
            }
        }
    }
    return 0;
}
