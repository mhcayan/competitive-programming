#include<stdio.h>
#include<math.h>
int main()
{
	long n,c=1;
	double a,s,u,v,t;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		else if(n==1)
		{
			scanf("%lf %lf %lf",&u,&v,&t);
			printf("Case %ld: %.3lf %.3lf\n",c,(u+v)*t/2,(v-u)/t);

		}
		else if(n==2)
		{
			scanf("%lf %lf %lf",&u,&v,&a);
			t=(v-u)/a;
			s=(u+v)*t/2;
			printf("Case %ld: %.3lf %.3lf\n",c,s,t);
		}
		else if(n==3)
		{
			scanf("%lf %lf %lf",&u,&a,&s);
			v=sqrt(u*u+2*a*s);
			t=(v-u)/a;
			printf("Case %ld: %.3lf %.3lf\n",c,v,t);
		}
		else
		{
			scanf("%lf %lf %lf",&v,&a,&s);
			u=sqrt(v*v-2*a*s);
			t=(v-u)/a;
			printf("Case %ld: %.3lf %.3lf\n",c,u,t);
		}
		c++;
	}
	return 0;
}