#include<stdio.h>
#include<conio.h>

int main()
{
	int prcss[100];
	int cbt[100]; 
	int rmn[100];
	int stk[100];
	int wt[100];
	int sum[100];
	int prcss1[100];
	int qt=4;

	int n,y,p=0;
	wt[0]=0;
	sum[0]=0;
    printf("No.of processes:\n");
	scanf("%d",&n);
    printf("Enter process number\n");
	for(int i=0;i<n;i++)
	{
	   scanf("%d",&prcss[i]);
	}
    printf("Enter cpu burst time\n");
	for(int j=0;j<n;j++)
	{
	   scanf("%d",&cbt[j]);
	}
    
	int m=0;
 /*   for(int k=0;k>n;k++)
	{
	   printf("%d",cbt[k]);
	}*/
int flag=0;
while(1)
{
	if(flag!=1)
	{
	  for(int x=0;x<n;x++)
	  {
	   if(cbt[x]>qt)
	   {
	      rmn[m]=cbt[x]-qt;
          stk[m]=prcss[x];
          prcss1[p]=prcss[x];
		  sum[p+1]=sum[p]+qt;
		  m++;
		  p++;
	   }
	   else
	   {
          prcss1[p]=prcss[x];
	      sum[p+1]=sum[p]+cbt[x];
		  p++;
	   }
	  }
	  flag=1;
	}
	else
	{
		int l=0;
	    y=l;
	    for(int z=0;z<m;z++)
		{
		   if(rmn[z]>qt)
		   {
		      rmn[y]=rmn[z]-qt;
			  stk[y]=stk[z];
			  prcss1[p]=stk[z];
			  sum[p+1]=sum[p]+qt;
			  y++;
			  p++;
		   }
		   else
		   {
			   prcss1[p]=stk[z];
		       sum[p+1]=sum[p]+rmn[z];
			  p++;
		   }
		}
		m=y;
	}
	if(y==0)
	{
	  break;
	}
}
printf("\n");

for(int r=0;r<p;r++)
{
  printf("P%d ",prcss1[r]);
}
printf("\n");

for(int s=0;s<p;s++)
{
  if(sum[s+1]>=cbt[prcss1[s]-1])
  {
     wt[prcss1[s]-1]=sum[s+1]-cbt[prcss1[s]-1];
  }

}
for(int t=0;t<n;t++)
{
	printf("waiting time for process %d =%d \n",prcss[t],wt[t]);
}
printf("\n");
getch();
 return 0;
}