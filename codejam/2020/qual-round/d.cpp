#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define ff first
#define ss second
#define pii pair<int,int>
#define piii pair<pii,int>
#define psi pair<string,int>
#define eps 1e-11
#define mod 100000007
#define endl '\n'
const int inf=2000000000;
#define SZ 105
#define R 1
#define C 2
#define RC 3

int ans[SZ];

void update(int pos, int len, int operation) {
	
	switch(operation) {
		
		case R:
			for(int i = 0; i < pos; i++) {
				swap(ans[i], ans[len - 1 - i]);
			}
			break;
		case C:
			for(int i = 0; i < pos; i++) {
				ans[i] = ans[i] ^ 1;
				ans[len - 1 - i] = ans[len - 1 - i] ^ 1;
			}
			break;
		case RC:
			for(int i = 0; i < pos; i++) {
				swap(ans[i], ans[len - 1 - i]);
				ans[i] = ans[i] ^ 1;
				ans[len - 1 - i] = ans[len - 1 - i] ^ 1;
			}
			break;
	}
}

int get_diff_loc(int pos, int len) {
	
	for(int i = 0 ; i < pos; i++) {
		if(ans[i] != ans[len - 1 - i]) {
			return i;
		}
	}
	return -1;
}

int get_same_loc(int pos, int len) {
	
	for(int i = 0; i < pos; i++) {
		if(ans[i] == ans[len -1 - i]) {
			return i;
		}
	}
	return -1;
}

inline int query(int pos) {
	
	printf("%d\n", pos + 1);
	fflush(stdout);
	int v;
	scanf("%d", &v);
	return v;	
}

int main() {
	
    int cas, len;
    scanf("%d", &cas);
    scanf("%d", &len);
    for(int tc = 1; tc <= cas; tc++) {
    	int pos = 0;
    	int q = 0;
    	while(1) {
    		
    		if(pos > len - 1 - pos) {
    			break;
			}
			
    		if(q > 1 && q % 10 == 0) {
    			//printf("hoho\n");
    			int diff_loc = get_diff_loc(pos, len);
    			int same_loc = get_same_loc(pos, len);
    			
				if(diff_loc == -1) {
    				int s1_value = query(same_loc);
					int s2_value = query(len - 1 - same_loc);
					q += 2;
					if(s1_value == ans[same_loc] && s2_value == ans[len - 1 - same_loc]) { //R or NOP
						//update(pos, len, NOP);
					} else { //R
						update(pos, len, C);
					}
				} else if(same_loc == - 1) {
					int d1_value = query(diff_loc);
					int d2_value = query(len - 1 - diff_loc);
					q += 2;
					if(d1_value == ans[diff_loc] && d2_value == ans[len - 1 - diff_loc]) {
						//update(pos, len, NOP);
					} else {
						update(pos, len, C);
					}
					
				} else {
					
					int d_value = query(diff_loc);
					int s_value = query(same_loc);
					q += 2;
					if(d_value == ans[diff_loc]) { //RC or NOP
					
						if(s_value == ans[same_loc]) { //NOP
							//update(pos, len, NOP);
						} else { //RC
							update(pos, len, RC);
						}
					} else { //C or R
					
						if(s_value == ans[same_loc]) { //R
							update(pos, len, R);
						} else {
							update(pos, len, C);
						}
					}
				}
    			
			} else {
			    ans[pos] = query(pos);
			    if(pos != len - 1 - pos)
    				ans[len - 1 - pos] = query(len - 1 - pos);
    			q += 2;
    			pos++;
			}
		}

		for(int i = 0; i < len; i++) {
			printf("%d", ans[i]);
		}
		printf("\n");
		fflush(stdout);
		string verdict;
		cin>>verdict;
		assert(verdict == "Y");
	}	
    return 0;
}
