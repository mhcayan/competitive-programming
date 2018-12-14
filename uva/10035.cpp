#include<stdio.h>
#include<string.h>
int main()
{
	char a[20],b[20];
	int co,c,sum,i,j;
	while(1)
	{
		scanf("%s %s",a,b);
		if(a[0]=='0'&&b[0]=='0')
			break;
		i=strlen(a)-1;
		j=strlen(b)-1;
		c=0;
		co=0;
		while(i>=0 && j>=0)
		{
            sum=c+a[i]-'0'+b[j]-'0';
			if(sum>9)
			{
				c=sum/10;
				co++;
			}
			else
				c=0;
			i--;
			j--;
		}
		if(i<0)
		{
			while(j>=0)
			{
				sum=c+b[j]-'0';
				if(sum>9)
				{
					c=sum/10;
					co++;
				}
				else
					break;
				j--;
			}
		}
		if(j<0)
		{
			while(i>=0)
			{
				sum=c+a[i]-'0';
				if(sum>9)
				{
					c=sum/10;
					co++;
				}
				else
					break;
				i--;
			}
		}
		if(co)
			printf("%d carry operations.\n",co);
		else
			printf("No carry operation.\n");
	}
	return 0;
}

