#include<stdio.h>
int main()
{
	while(gets(str))
	{
		while(strcmp(str,"deadend")!=0)
		{
			l=strlen(str);
			if(loc[str[0]]==-1)
				loc[str[0]]=no++;
			if(loc[str[l-1]]==-1)
				loc[str[l-1]]=no++;
			p=loc[str[0]];
			q=loc[str[l-1]];
			cost[p][q]=1;
