#include<stdio.h>
#include<string.h>
int rev(char *from,char *to,int l)
{
	l--;
	for(int i=0;i<=l;i++)
		to[i]=from[l-i];
	to[i]='\0';
	return 0;
}
int mul(char *a,char *b,char *result)
{
	char temp[10000],F[10000],S[10000];
	int f,s,i,j,r,hold,res;
	f=strlen(a);
	s=strlen(b);
	rev(a,F,f);
	rev(b,S,s);
	r=f+s;
	for(i=0;i<r;i++)
		temp[i]='0';
	r=-1;
	for(i=0;i<f;i++)
	{
		hold=0;
		for(j=0;j<s;j++)
		{
			res=(F[i]-'0')*(S[j]-'0')+hold+(temp[i+j]-'0');
			temp[i+j]=res%10+'0';
			hold=res/10;
		//	if(i+j>r)
	     //		r=i+j;
		}
		if(i+j-1>r)
			r=i+j-1;
		if(hold)
		{
			temp[i+j]=hold+'0';
			if(i+j>r)
				r=i+j;
		}
	}
	for(i=r;i>0&&temp[i]=='0';i--);
	temp[i+1]='\0';
	rev(temp,result,i+1);   //i+1=length of temp;
	return 0;
}
int main()
{
	char a[10000],b[10000],res[10000];
	while(gets(a))
	{
		gets(b);
		mul(a,b,res);
		printf("%s\n",res);
	}
	return 0;
}