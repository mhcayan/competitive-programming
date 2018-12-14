#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=2000000000;
int main()
{
	double R1[50][50],R2[50][50],M[50][50];
    int r1,r2,c1,c2,i,j,k;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(1)
	{
		printf("Number of rows and columns in realation R1(enter 0 0 to exit)\n");
		scanf("%d %d",&r1,&c1);
		if(r1==0)
			break;
		for(i=0;i<r1;i++)
			for(j=0;j<c1;j++)
			    scanf("%lf",&R1[i][j]);
		printf("Number of rows and columns in realation R2\n");
		scanf("%d %d",&r2,&c2);
		for(i=0;i<r2;i++)
			for(j=0;j<c2;j++)
			    scanf("%lf",&R2[i][j]);
        printf("Max-Min Composition of R1 and R2 is:\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				M[i][j]=-inf;
				for(k=0;k<c1;k++)
					M[i][j]=max(M[i][j],min(R1[i][k],R2[k][j]));
				printf("%.1lf ",M[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
