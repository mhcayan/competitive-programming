#include<stdio.h>
#include<string.h>
int main()
{
	char s[50];
	int t,c,i,l,m;
	scanf("%d",&c);
	getchar();
	for(t=1;t<=c;t++)
	{
		gets(s);
		l=strlen(s);
		m=l/2;
		l--;
		for(i=0;i<m;i++)
		{
			if(s[i]!=s[l-i])
				break;
		}
		if(i==m)
			printf("Case %d: Yes\n",t);
		else
			printf("Case %d: No\n",t);
	}
	return 0;
}