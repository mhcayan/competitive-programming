#include<stdio.h>
#include<string.h>
int rev(char *from,char *to)
{
	int l,i;
	l=strlen(from)-1;
	for(i=0;i<=l;i++)
	{
		to[i]=from[l-i];
	}
	to[i]='\0';
	return 0;
}
int swap(char *a,char *b)
{
	char t[100];
	strcpy(t,a);
	strcpy(a,b);
	strcpy(b,t);
	return 0;
}
int sub(char *lar,char *small,char *res)
{
	int  l,s,t,i,sign=0,carry,diff;
	char L[100],S[100];
	l=strlen(lar);
	s=strlen(small);
	if(l<s)
	{
		swap(lar,small);
		t=s;s=l;l=t;
		sign=1;
	}
	else if(l==s)
	{
		if(strcmp(lar,small)<0)
		{
			swap(lar,small);
			t=s;s=l;l=t;
			sign=1;
		}
	}
	rev(lar,L);
	rev(small,S);
	for(;s<l;s++)
		S[s]='0';
	S[s]='\0';
	carry=0;
	for(i=0;i<l;i++)
	{
		diff=L[i]-(S[i]+carry);
		if(diff<0)
		{
			res[i]=diff+10+'0';
			carry=1;
		}
		else
		{
			res[i]=diff+'0';
			carry=0;
		}
	}
	for(i=l-1;i>0;i--)
	{
		if(res[i]!='0')
			break;
	}
	res[i+1]='\0';
	rev(res,lar);
	swap(res,lar);
	return sign;
}
int main()
{
	int s;
	char a[100],b[100],res[100];
	while(gets(a))
	{
		gets(b);
		s=sub(a,b,res);
		if(s)
			printf("-");
		printf("%s\n",res);
	}
	return 0;
}