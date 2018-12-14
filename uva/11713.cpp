#include<stdio.h>
#include<string.h>
int main()
{
	int n,l,i;
	char a[21],b[21];
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		gets(a);
		gets(b);
		l=strlen(a);
		if(l==strlen(b))
		{
			for(i=0;i<l;i++)
			{
				if(b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='o'||b[i]=='u')
				{
					if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
					{
			
					}
					else
					{
						printf("No\n");
						break;
					}
				}
				else
				{
					if(a[i]!=b[i])
					{
						printf("No\n");
					    break;
					}
				}
			}
			if(i==l)
				printf("Yes\n");
		}
		else
			printf("No\n");
	}
	return 0;
}