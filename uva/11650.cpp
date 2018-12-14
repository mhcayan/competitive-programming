#include<stdio.h>
int main()
{
	char str[20];
	int t,h,m;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(str);
		sscanf(str,"%d:%d",&h,&m);
		if(m>0)
			m=60-m;
		if(h<12)
			h=12-h;
		if(m)
			h--;
		if(h==0)
			h=12;
		if(h<10)
			printf("0");
		printf("%d:",h);
		if(m<10)
			printf("0");
		printf("%d\n",m);
	}
	return 0;
}