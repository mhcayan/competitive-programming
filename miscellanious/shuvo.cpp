#include<stdio.h>
#include<conio.h>
int main()
{
    int process,hole,allocation[100],partition[100],process_executed[100],check,count,used,i,j,k;
    printf("\nHow many process do you want to execute?: \n");
    scanf("%d",&process);
    printf("\nHow many partition do U want to create?: \n");
    scanf("%d",&hole);
    for(i=0;i<process;i++)
    {
                          printf("Enter Memeory Allocation for Process[%d]",i+1);
                          scanf("%d",&allocation[i]);
    }
    for(i=0;i<hole;i++)
    {
                       printf("Enter size for partition[%d]",i+1);
                       scanf("%d",&partition[i]);
    }
    
    for(i=0;i<process;i++)
	{
		for(j=0;j<hole;j++)
		{
			check=0;
			if(partition[j]>allocation[i])
			{
				used=partition[j]-allocation[i];
				partition[i]=j;
				check=1;
				break;
			}
		}
		if(check==1)
		{
			printf("Process[%d] is in Partition[%d] where Partition[%d-%d]=%d\n",i+1,j,partition[j],allocation[i],used);
		}
		else
		{
			printf("Process[%d] is in waiting state.",i+1);
		}
	}
	getch();
	return 0;
}
