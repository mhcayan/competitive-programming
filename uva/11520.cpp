#include<stdio.h>
int main()
{
	char a[100][100],ch,flag;
	int t,i,j,c,n;
	scanf("%d",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			getchar();
			for(j=1;j<=n;j++)
			    scanf("%c",&a[i][j]);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]=='.')
				{
					ch='A';
					while(1)
					{
						flag=0;
					    if(i-1>0 && a[i-1][j]==ch)
						    flag=1;
					    else if(i+1<=n && a[i+1][j]==ch)
						    flag=1;
					    else if(j-1>0 && a[i][j-1]==ch)
						    flag=1;
					    else if(j+1<=n && a[i][j+1]==ch)
						    flag=1;
					    if(flag==0)
						{
						    a[i][j]=ch;
						    break;
						}
					    else
						    ch++;
					}
				}
			}
		}
		printf("Case %d:\n",t);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				printf("%c",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}





			





