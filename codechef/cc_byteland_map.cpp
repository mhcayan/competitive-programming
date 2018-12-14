#include<iostream>
#include<map>
#include<iterator>
#include<cstdio>
using namespace std;
map<unsigned long,unsigned long>memo;

unsigned long fun(unsigned long n)
{
	map<unsigned long,unsigned long>::iterator iter=memo.find(n);
	if(iter!=memo.end())
		return iter->second;
	else
	{
		unsigned long p;
		p=fun(n/2)+fun(n/3)+fun(n/4);
		p=n>p?n:p;
		memo.insert(make_pair(n,p));
		return p;
	}
}
int main()
{
	unsigned long i,n;
	for(i=0;i<12;i++)
		memo.insert(make_pair(i,i));
	while(scanf("%lu",&n)==1)
	{
		printf("%lu\n",fun(n));
	}
	return 0;
}
