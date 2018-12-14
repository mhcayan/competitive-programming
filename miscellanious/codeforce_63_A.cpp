#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n;
	string name,group;
	scanf("%d",&n);
	while(n--)
	{
		cin>>name>>group;
		cout<<name<<group<<endl;
	}
	return 0;
}