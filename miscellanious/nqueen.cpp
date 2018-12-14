#include<stdio.h>
#include<math.h>
int a[100],sol,n;
void nqueen(int k,int n);
int check(int k,int i);
int main()
{
    printf("HOW MANY QUEENS:\n");
	scanf("%d",&n);
	nqueen(1,n);
	printf("\nTOTAL NO OF SOLUTION=%d\n",sol);
	return 0;
}
void nqueen(int k,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(check(k,i))
		{
			a[k]=i;
			if(k==n)
			{
				for(int p=1;p<=n;p++)
					printf("%d ",a[p]);
				printf("\n");
				sol++;
			}
			else
				nqueen(k+1,n);
		}
	}
}
int check(int k,int i)
{
	int j;
	for(j=1;j<k;j++)
	{
		if(a[j]==i || (abs(j-k)==abs(i-a[j])))
			return 0;
	}
	return 1;
}