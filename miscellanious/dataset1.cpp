#include<string>
#include<cstdio>
using namespace std;
#define mod 1000000007
char digit[11]={'0','1','2','3','4','5','6','7','8','9','.'};
char letter[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','_','+','-','+','*','/',',','.','%'};
int main()
{
    char s[10000];
    int i,j,l,c;
    //printf("%d\n",strlen(letter));
    freopen("dataset1.txt","w",stdout);
    srand(time(NULL));
    for(i=0;i<500;i++)
        printf("%d%d\n",rand()%mod,rand()%mod);
    for(i=0;i<500;i++)
        printf("%d.%d\n",rand()%mod,rand()%mod);
    for(i=0;i<500;i++)
    {
        l=rand()%1000;
        c=0;
        for(j=0;j<l;j++)
            s[c++]=letter[rand()%71];
        s[c]='\0';
        printf("%s\n",s);
    }
    for(i=0;i<500;i++)
    {
        l=rand()%100;
        c=0;
        for(j=0;j<l;j++)
            s[c++]=digit[rand()%11];
        s[c]='\0';
        printf("%s\n",s);
    }
  //  getchar();
//        getchar();
    return 0;
}

