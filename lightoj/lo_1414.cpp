#include<stdio.h>
#include<string.h>
int main()
{
    int cas,tc,d1,y1,d2,y2,n,l1,l2;
    char m1[10],m2[10];
    scanf("%d",&cas);
    for(tc=1;tc<=cas;tc++)
    {
        scanf("%s %d, %d",&m1,&d1,&y1);
        scanf("%s %d, %d",&m2,&d2,&y2);
        n=y2/4-y2/100+y2/400-(y1/4-y1/100+y1/400);
        if(y1%4==0)
        {
            if(y1%400!=0 && y1%100==0)
               l1=0;
            else
               l1=1;
        }
        else
            l1=0;
        if(y2%4==0)
        {
            if(y2%400!=0 && y2%100==0)
               l2=0;
            else
               l2=1;
        }
        else
            l2=0;
        if(y1==y2)
        {
            if(l1)
            {
                if(strcmp(m1,"January")==0 || (strcmp(m1,"February")==0 && d1<30))
                {
                    if(!(strcmp(m2,"January")==0 || (strcmp(m2,"February")==0 && d2<29)))
                        n++;
                }
            }
        } 
        else
        {   
            if(l1 && (strcmp(m1,"January")==0 || (strcmp(m1,"February")==0 && d1<30)))
                n++;
            if(l2)
            {
                if(strcmp(m2,"January")==0 || (strcmp(m2,"February")==0 && d2<29))
                    n--;
            }
        }
        printf("Case %d: %d\n",tc,n);        
    }
    return 0;
}
