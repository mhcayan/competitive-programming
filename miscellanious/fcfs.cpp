#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
typedef struct{
	int no,bt,ar;
}process;
int cmp(const void *a,const void *b)
{
	process *x=(process *)a;
	process *y=(process *)b;
	return x->ar-y->ar;
}
int main()
{
	int n,i,total1,total2,wt[100],tat[100],t;
	process p[100];
	while(scanf("%d",&n)==1)
	{
		printf("Enter process number:\n");
		for(i=0;i<n;i++)
			scanf("%d",&p[i].no);
		printf("Enter cpu burst time of the processes:\n");
		for(i=0;i<n;i++)
			scanf("%d",&p[i].bt);
		printf("Enter arrival order of the process:\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			p[t-1].ar=i;
		}
		qsort(p,n,sizeof(p[0]),cmp);
		tat[0]=p[0].bt;
		wt[0]=0;
		total1=0;
		total2=tat[0];
		for(i=1;i<n;i++)
		{
			tat[i]=tat[i-1]+p[i].bt;
			total2+=tat[i];
			wt[i]=tat[i-1];
			total1+=wt[i];
		}
		printf("Process order --  waiting time -- turn around time\n");
		for(i=0;i<n;i++)
			printf("    %2d     %2d     %2d     \n",p[i].no,wt[i],tat[i]);
		printf("Average waiting time=%.2lf\nAverage turn arond time=%2lf\n",(double)total1/n,(double)total2/n);
	}
	return 0;
}
