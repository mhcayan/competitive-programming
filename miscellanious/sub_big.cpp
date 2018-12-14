#include<stdio.h>
#include<string.h>
int sub(char *lar,char *small,char *res)
{
	l=strlen(a);
	s=stelen(b);
	if(l<s)
	{
		change(large,small);
		t=s;s=l;l=t;
	}
	else if(l==s)
	{
		if(strcmp(a,b)<0)
		{
			change(a,b);
			t=s;s=l;l=t;
		}
	}
	rev(lar,L);
	rev(small,S);
	for(;s<l;s++)
		S[s]='0';
	s[s]='\0';
	for(i=0;i<s && i<l;i++)
	{

}
int main()
{
	while(gets(a))
	{
		gets(b);
		s=sub(a,b,res);
		if(s)
			printf("-1");
		printf("%s\n",res);
	}
	return 0;
}