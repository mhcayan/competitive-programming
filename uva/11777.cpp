#include<stdio.h>
int main()
{
	float total;
	int t,t1,t2,f,a,c1,c2,c3,i=1,m;
	char g;
	scanf("%d",&t);
	while(i<=t)
	{
		scanf("%d %d %d %d %d %d %d",&t1,&t2,&f,&a,&c1,&c2,&c3);
		if(c1<c2)
		{
			if(c1<c3)
				m=c1;
			else
				m=c3;
		}
		else
		{
			if(c2<c3)
				m=c2;
			else
				m=c3;
		}
		m=c1+c2+c3-m;
		total=(float)m/2;
		total+=t1+t2+f+a;
		if(total<60)
			g='F';
		else if(total>=90)
			g='A';
		else if(total>=80 && total<90)
			g='B';
		else if(total>=70 && total<80)
			g='C';
		else
			g='D';
		printf("Case %d: %c\n",i,g);
		i++;
	}
	return 0;
}

