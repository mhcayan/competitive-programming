#include<stdio.h>
#include<string.h>
char status[1000];
int main()
{
	char a[50][50],b[50][50],s[1000];
	status['a']=1;status['e']=1;status['i']=1;status['o']=1;status['u']=1;
	int l,n,i,j,len;
	while(scanf("%d %d",&l,&n)==2)
	{
		for(i=0;i<l;i++)
		{
			scanf("%s %s",a[i],b[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			for(j=0;j<l;j++)
			{
				if(!strcmp(s,a[j]))
				{
					printf("%s\n",b[j]);
					break;
				}
			}
			if(j<l)
				continue;
			len=strlen(s)-1;
			if(len==0)
			{
				if(s[0]=='s' && s[0]=='o' &&s[0]=='x')
				     strcat(s,"es");
				else
					strcat(s,"s");
			}
			else if(s[len]=='y' && status[s[len-1]]==0)
			{
				s[len++]='i';
				s[len++]='e';
				s[len++]='s';
				s[len]='\0';
				
			}
			else if(s[len]=='o'||s[len]=='s'||s[len]=='x'||(s[len-1]=='c'&&s[len]=='h')||(s[len-1]=='s'&&s[len]=='h'))
			{
				strcat(s,"es");
			}
			else
			{
				strcat(s, "s");
			}
			printf("%s\n",s);
		}
	}
	return 0;
}

