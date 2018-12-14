#include<stdio.h>
#include<math.h>
long s;
int a[100],sol,n;
void nqueen(int k,int n);
int check(int k,int i);
int main()
{
    printf("HOW MANY QUEENS:\n");
	scanf("%d",&n);
	nqueen(1,n);
	printf("\nTOTAL NO OF SOLUTION=%d\nTOTAL STEPS=%ld\n",sol,s);
	return 0;
}
void nqueen(int k,int n)
{
	int i;
	for(i=1,s++;i<=n;i++,s++)
	{
		if(check(k,i))
		{
			a[k]=i;
			s+=2;
			if(k==n)
			{
				/*for(int p=1;p<=n;p++)
					printf("%d ",a[p]);
				printf("\n");*/
				sol++;
			}
			else
			{
				nqueen(k+1,n);
				s++;
			}
		}
	}
}
int check(int k,int i)
{
	int j;
	for(j=1,s++;j<k;j++,s++)
	{
		if(a[j]==i || (abs(j-k)==abs(i-a[j])))
		{
			s+=4;
			return 0;
		}
	}
	s++;
	return 1;
}