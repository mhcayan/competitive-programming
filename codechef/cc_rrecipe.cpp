#include<stdio.h>
#include<string.h>
int main()
{
    int t,ans,i,j;
    char s[1000002];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&s);
        j=strlen(s)-1;
        i=0;
        ans=1;
        while(i<=j)
        {
            if(s[i]=='?' && s[j]=='?')
                ans=(ans*26)%10000009;
            else if(s[i]!='?' && s[j]!='?' && s[i]!=s[j])
            {
                ans=0;
                break;
            }
            i++,j--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
