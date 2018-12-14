#include<cstdio>
#include<cstring>
using namespace std;
struct Trie
{
	int value;
	Trie *child[2];
	Trie()
	{
		value = 0;
		child[0] = NULL;
		child[1] = NULL;
	}
};

Trie* go(Trie *cur, char *str, int pos = 0)
{
	if(str[pos] == '\0'){
		return cur;
	}
	int d = str[pos] - '0';
	if(cur->child[d] == NULL){
		cur->child[d] = new Trie();
	}
	return go(cur->child[d], str, pos+1);
}
//Trie* go(Trie *cur, char *str)
//{
//	for(int i = 0; str[i]; i++){
//		int d = str[i] - '0';
//		if(cur->child[d] == NULL){
//			cur->child[d] = new Trie();
//		}
//		cur = cur->child[d];
//	}
//	return cur;
//}

void update(Trie *cur, char *str, int add){
	cur = go(cur, str);
	cur->value += add;
}

int find(Trie *cur, char *str){
	cur = go(cur, str);
	return cur->value;
}

void num2Str(long long num, char *str)
{
	int indx = 0;
	while(num > 0){
		str[indx++] = (num % 10) % 2 + '0';
		num = num / 10;
	}
	str[indx] = '\0';
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

int main()
{
	int query;
	long long num;
	char str[25], q;
	scanf("%d", &query);
	Trie *head = new Trie();
	while(query--)
	{
		scanf(" %c", &q);
		scanf("%I64d", &num);
		num2Str(num, str);
		removeTrailingZeros(str);
		if(q == '+')
		{
			update(head, str, 1);
		} 
		else if(q == '-') 
		{
			update(head, str, -1);
		} 
		else 
		{
			printf("%d\n",find(head, str));
		}
	}	
	return 0;
}
