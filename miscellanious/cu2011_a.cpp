#include<stdio.h>
#include<string.h>
int main()
{
	char a[11][10],s[1000];
	long t,i,j,n;
	a[1][0]='\0';
	a[0][0]='\0';
	strcpy(a[2],"abc");
	strcpy(a[3],"def");
	strcpy(a[4],"ghi");
	strcpy(a[5],"jkl");
	strcpy(a[6],"mno");
	strcpy(a[7],"pqrs");
	strcpy(a[8],"tuv");
	strcpy(a[9],"wxyz");
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		bool flag=0;
		gets(s);
		scanf("%ld",&n);
		getchar();
		for(i=0;s[i];i++)
		{
			for(j=0;a[n][j];j++)
			{
				if(a[n][j]==s[i])
				{
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}
