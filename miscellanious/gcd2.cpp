#include<stdio.h>
int fact(int n)
{
    if(n==0)
    return 1;
    int i;
  int    f=1;
    for(i=1;i<=n;i++)
    f=f*i;
    return f;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
                            printf("%d\n",fact(n));
                            }
                            return 0;
                            }

