#include<stdio.h>
char s[2000003];
int main()
{
	long l,flag,dis,min,i,loc;
	while(scanf("%ld",&l)&&l)
	{
		scanf("%s",&s);
		flag=0;
		min=9999999;
		for(i=0;i<l;i++)
		{
			if(s[i]=='Z')
				break;
			else if(s[i]=='D')
			{
				if(flag==2) 
				{
					dis=i-loc;
					if(dis<min)
						min=dis;
				}
				flag=1;
				loc=i;
			}
			else if(s[i]=='R')
			{
				if(flag==1)
				{
					dis=i-loc;
					if(dis<min)
						min=dis;
				}
				flag=2;
				loc=i;
			}
		}
		if(s[i]=='Z')
			printf("0\n");
		else
			printf("%ld\n",min);
	}
    return 0;
}
