#include<stdio.h>
#include<stdlib.h>
int main()
{
    int cas,u,v,i;
    freopen("input_file2.txt","w",stdout);
    scanf("%d",&cas);
    printf("%d\n",cas);
    
    while(cas--)
    {
        freopen("rep_input2.txt","r",stdin);
        printf("91 %d\n",rand()%60+1);
        for(i=0;i<91;i++)
            printf("%d ",rand()%40);
        printf("\n");
        for(i=0;i<90;i++)
        {
            scanf("%d %d",&u,&v);
            printf("%d %d %d\n",u,v,rand()%40+1);
        }
    }
    return 0;
}
