#include<stdio.h>
#include<string.h>
int main()
{
	char a[200][200],s[1000];
	int t,i,j,p,cas=1;
	while(scanf("%d",&t))
	{
		if(!t)
			break;
		for(i=0;i<t;i++)
		{
			do
			{
			   gets(s);
			}while(s[0]=='\0');
			strcpy(a[i],"printf(\"");
			p=8;
			for(j=0;s[j];j++)
			{
				if(s[j]=='\\' || s[j]=='\"')
					a[i][p++]='\\';
				a[i][p++]=s[j];
			}
			a[i][p]='\0';
			strcat(a[i],"\\n\");");
		}
		printf("Case %d:\n",cas++);
		printf("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");
		for(i=0;i<t;i++)
			printf("%s\n",a[i]);
		printf("printf(\"\\n\");\nreturn 0;\n}\n");
	}
	return 0;
}
