#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
typedef struct{
	int pn,bt;
}process;
int cmp(const void *a,const void *b)
{
	process *x=(process*)a;
	process *y=(process*)b;
	return x->bt-y->bt;
}
int main()
{
	process p[100];
	int n,i,wt[100],tat[100],t1,t2;
	printf("Enter no. of processes:\n");
	scanf("%d",&n);
	printf("Enter process number:\n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i].pn);
	printf("Enter cpu burst time of the processes:\n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i].bt);
	qsort(p,n,sizeof(process),cmp);
	wt[0]=0;
	t1=0;
	tat[0]=t2=p[0].bt;
	for(i=1;i<n;i++)
	{
		wt[i]=tat[i-1];
		tat[i]=wt[i]+p[i].bt;
		t1+=wt[i];
		t2+=tat[i];
	}
	printf("\nProcess order---waiting time---turn around time\n");
	for(i=0;i<n;i++)
		printf("     %2d            %2d            %2d     \n",p[i].pn,wt[i],tat[i]);
	printf("\nAverage waiting time=%.2lf\n\n",(double)t1/n);
	printf("Average turn around time=%.2lf\n",(double)t2/n);
	return 0;
}




