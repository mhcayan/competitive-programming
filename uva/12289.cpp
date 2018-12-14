#include<stdio.h>
#include<string.h>
int main()
{
	char *s1="one",s[100];
	int t,error,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		if(strlen(s)==3)
		{
			error=0;
		    for(i=0;s1[i];i++)
			{
			    if(s1[i]!=s[i])
				   error++;
			}
		    if(error<=1)
			    printf("1\n");
		    else
				printf("2\n");
		}
		else
			printf("3\n");
	}
	return 0;
}
