#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int t,m,n,a[10][110],sonar,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		m=m-1;
		n=n-1;
		if(m<2 || n<2)
			printf("0\n");
		else if(m==2)
		{
			printf("%.0f\n",ceil((n-1)/3));
		}
		else if(n==2)
		{
			printf("%.0f\n",ceil((m-1)/3));
		}
		else
		{
			memset(a,0,sizeof(a));
			sonar=0;
			i=3;
			while(i<=m)
			{
				j=3;
				while(j<=n)
				{
					if(a[i][j]==0)
					{
						a[i][j]=1;
						a[i-1][j]=1;
						a[i+1][j]=1;
						a[i][j-1]=1;
						a[i][j+1]=1;
						a[i+1][j+1]=1;
						a[i-1][j-1]=1;
						a[i+1][j-1]=1;
						a[i-1][j+1]=1;
						sonar++;
					}
					j+=3;
					if(j>n)
						j--;
				}
				i+=3;
				if(i>m)
					i--;
			}
			printf("%d\n",sonar);
		}
	}
	return 0;
}