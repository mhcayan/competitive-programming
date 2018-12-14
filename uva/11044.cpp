#include<stdio.h>
#include<math.h>
int main()
{
	float t,m,n;
	scanf("%f",&t);
	while(t--)
	{
		scanf("%f %f",&m,&n);
		m=m-2;
		n=n-2;
		printf("%.0f\n",ceil(m/3)*ceil(n/3));
	}
	return 0;
}
