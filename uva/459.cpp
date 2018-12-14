#include<stdio.h>
int Union(char a,char b);
char find(char a);
char par[1000];
int main()
{
	char ch,mch,s[1000];
	int t,com;
	scanf("%d\n",&t);
	while(t--)
	{
		scanf("%c",&mch);
		getchar();
		for(ch='A';ch<=mch;ch++)
		{
			//vis[ch]=0;
			par[ch]=ch;
		}
        //vis[mch]=1;
		while(gets(s)&&s[0]!='\0')
		{
		
			Union(s[0],s[1]);
			//vis[s[0]]=1;
			//vis[s[1]]=1;
		}
		com=0;
		for(ch='A';ch<=mch;ch++)
		{
			if(par[ch]==ch)
				com++;
		}
		printf("%d\n",com);
		if(t)
			printf("\n");
	}
	return 0;
}
int Union(char a,char b)
{
	char p,q;
	p=find(a);
	q=find(b);
	if(p!=q)
	    par[q]=p;
	return 0;
}
char find(char a)
{
	if(par[a]==a)
		return a;
	else
	    return par[a]=find(par[a]);
}


		