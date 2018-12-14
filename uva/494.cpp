#include<stdio.h>
int alpha(char ch);
int main()
{
	char a[1000];
	int i,count;
	while(gets(a))
	{
		count=0;
		if(alpha(a[0]))
			count++;
		for(i=1;a[i]!='\0';i++)
		{
			if(alpha(a[i]) && !alpha(a[i-1]))
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
int alpha(char ch)
{
	if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
		return 1;
	else
		return 0;
}
