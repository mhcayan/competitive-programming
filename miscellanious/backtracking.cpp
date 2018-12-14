#include<bits/stdc++.h>
using namespace std;
bool vis[100];
int a[100];
//prints all permutation from of numbers from 0 to (n-1)
void print(int cur, int n) {
	if(cur == n) {
		for(int i = 0; i < n; i++) {
			printf("%2d ", a[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 0; i < n; i++) {
		if(vis[i] == false) {
			a[cur] = i;
			vis[i] = true;
			print(cur+1, n);
			vis[i] = false;
		}
	}
}

char perm[100];
char str[100];
void stringPermutation(int cur, int len) {
	if(cur == len) {
		perm[len] = '\0';
		puts(perm);
		return;
	}
	for(int i = 0; i < len; i++) {
		if(vis[i] == false) {
			vis[i] = true;
			perm[cur] = str[i];
			stringPermutation(cur+1, len);
			vis[i] = false;
		}
	}
}

void stringPermWithNoRep(int pos, int len) {
	
	if(pos == len) {
		perm[len] = '\0';
		puts(perm);
		return;
	}
	
	bool isUsed[500];
	for(int i = 0; i < len; i++) {
		isUsed[str[i]] = false;
	}
	for(int i = 0; i < len; i++) {
		if(vis[i] == false && isUsed[str[i]] == false) {
			vis[i] = true;
			isUsed[str[i]] = true;
			perm[pos] = str[i];
			stringPermWithNoRep(pos+1, len);
			vis[i] = false;
		}
	}
}

int main() {
	while(gets(str)) {
		int len = strlen(str);
		for(int i = 0; i < len; i++) {
			vis[i] = false;
		}
		stringPermWithNoRep(0, len);
	}
	return 0;
}
