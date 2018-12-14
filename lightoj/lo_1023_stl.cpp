#include<iostream>
#include<algorithm>
using namespace std;
char s[29]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",a[30];
int main()
{
	int cas,t,n,k,i,count;
	cin>>cas;
	for(t=1;t<=cas;t++)
	{
		cin>>n>>k;
		for(i=0;i<n;i++)
			a[i]=s[i];
		a[i]='\0';
		count=0;
		cout<<"Case "<<t<<':'<<endl;
		do
		{
			count++;
			cout<<a<<endl;
		}while(next_permutation(a,a+n) && count<k);
	}
	return 0;
}


