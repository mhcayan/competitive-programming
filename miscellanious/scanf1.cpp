/* related acm:10194
 sample input:
6
Team A#1@1#Team B
Brazil#2@1#Scotland

sample output:
Team A 1 1 Team B
Brazil 2 1Scotland*/

#include<stdio.h>
int main()
{
	long n,g1,g2;
	char t1[100],t2[100];
	scanf("%ld",&n);
	getchar();
	while(n--)
	{
		scanf("%[^#]",t1);
		getchar();
		scanf("%ld",&g1);
		getchar();
		scanf("%ld",&g2);
		getchar();
		scanf("%[^\n]",t2);
		getchar();
		printf("%s %ld %ld %s\n",t1,g1,g2,t2);
	}
	return 0;
}