#include<stdio.h>
#include<string.h>
int main()
{
	char a[30],b[30],l[30];
	int t,c=1,i,j;
	scanf("%d",&t);
	getchar();
	while(c<=t)
	{
		gets(a);
		gets(b);
	    j=0;
		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]!=' ')
				l[j++]=a[i];
		}
	    l[j]='\0';
		if(!strcmp(l,b))
		{
			if(i==j)
				printf("Case %d: Yes\n",c);
			else
			    printf("Case %d: Output Format Error\n",c);
		}
        else
			printf("Case %d: Wrong Answer\n",c);
		c++;
	}
	return 0;
}


