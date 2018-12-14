
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<unsigned long,unsigned long>memo;
unsigned long fun(unsigned long n)
{
    if(memo.find(n)==memo.end())
		return memo[n]=max(n,fun(n/2)+fun(n/3)+fun(n/4));
    return memo[n];
}
int main()
{
    unsigned long n,i;
    for(i=0;i<12;i++)
		memo[i]=i;
    while(scanf("%lu",&n)==1)
		printf("%lu\n",fun(n));
    return 0;
}