/*

TASK: ride
LANG: C++                 
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 47

int getValue(string str) {
	int value = 1;
	for(int i = 0; str[i]; i++) {
		value = (value * (str[i] - 'A' + 1)) % M;
	}
	return value;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);
	string commet, group;
	cin>>commet;
	cin>>group;

	int cm = getValue(commet);
	int gm = getValue(group);

	if(cm == gm) {
		cout<<"GO"<<endl;
	} else {
		cout<<"STAY"<<endl;
	}
	return 0;
}
