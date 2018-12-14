#include<stdio.h>
#include<string.h>
int main()
{
    char str[100000];
    int i,dot,l;
    //freopen("dataset1.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    while(gets(str))
    {
        l=strlen(str);
        dot=0;
        for(i=0;i<l;i++)
        {
            if(str[i]>='0' && str[i]<='9')
                continue;
            else if(str[i]=='.')
            {
                dot++;
                if(dot>1)
                    break;
                continue;
            }
            else
                break;
        }
        if(i<l)
            printf("INVALID\n");
        else if(dot==1 && str[l-1]=='.')
            printf("INVALID\n");
        else
            printf("VALID\n");
    }
    return 0;
}
