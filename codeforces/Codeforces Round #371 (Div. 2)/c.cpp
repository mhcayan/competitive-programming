#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define N 502500

int T[N][2];
int A[N];
int BEGIN;

void reverse(char *str)
{
	int j = strlen(str) - 1;
	int i = 0;
	while(i < j)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
void init()
{
	BEGIN = 1;
	memset(A, 0, sizeof(A));
	memset(T, 0, sizeof(T));
}

int go(char *str)
{
	int len = strlen(str);
	int cur = 0;
	for(int i = 0; i < len; i++)
	{
		char d = str[i];
		if(T[cur][d] == 0)
		{
			T[cur][d] = BEGIN++;
		}
		cur = T[cur][d];
	}
	return cur;
}

void add(char *str)
{
	int cur = go(str);
	A[cur]++;
}

int find(char *str)
{
	int cur = go(str);
	return A[cur];
}

void del(char *str)
{
	int cur = go(str);
	A[cur]--;
}

void num2Str(long long num, char *arr)
{
	int indx = 0;
	while(num > 0){
		arr[indx++] = (num % 10) % 2 + '0';
		num = num / 10;
	}
	arr[indx] = '\0';
}

void removeTrailingZeros(char *str) 
{
	int j = strlen(str) - 1;
	while(j >= 0 && str[j] == '0')
	{
		j--;
	}
	str[j+1] = '\0';
	
}
int main(){
	int query;
	char q, str[88];
	long long num;
	scanf("%I64d", &query);
	init();
	while(query--)
	{
		scanf(" %c", &q);
		scanf("%I64d", &num);
		num2Str(num,str);
		removeTrailingZeros(str);
		if(q == '+') 
		{
			add(str);
		} 
		else if(q == '-') 
		{
			del(str);
		} 
		else 
		{
			printf("%d\n",find(str));
		}
	}
	return 0;
}
