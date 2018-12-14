#include<stdio.h>
int a[9][9],flag=0;
int check(int value[10],int l,int k);
void suduko(int l,int k)
{
	if(l==9)
	{
		flag=1; 	
	}
    else if(k==9)
	    suduko(l+1,0);
    else
	{
        if(a[l][k])
			suduko(l,k+1);
        else
		{  
            int value[10]={0};
	        check(value,l,k);
	        for(int i=1;i<=9;i++)
			{
				if(flag==1)
					return;
		        if(value[i]==0)
				{	
		        	a[l][k]=i;
		        	suduko(l,k+1);
				}
			}
	        if(flag==0)
                a[l][k]=0; 
		}
	}
}
int check(int value[10],int l,int k)
{
	int i,r,c,j;
    r=l-l%3;
	c=k-k%3;
	for(i=0;i<9;i++)
		value[a[l][i]]=1;
	for(i=0;i<9;i++)
		value[a[i][k]]=1;
	for(i=r;i<r+3;i++)
		for(j=c;j<c+3;j++)
			value[a[i][j]]=1;		     
    return 0;
}

int main()
{
	int i,j;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			scanf("%d",&a[i][j]);
    suduko(0,0);
    printf("\n\n");
    for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
    return 0;
}