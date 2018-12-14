#include<stdio.h>
#include<string.h>
int main()
{
	char name[101][101],n1[100],n2[100];
	long std,t,c,i,j,k,point[101],enemy[101][101],loc1,loc2,loc3,e,e1,e2,max,p,temp;
	scanf("%ld",&c);
	getchar();
	for(t=1;t<=c;t++)
	{
		scanf("%ld",&std);
		memset(enemy,0,sizeof(enemy));
		
		for(i=0;i<std;i++)
		{
			scanf("%s %ld",name[i],&point[i]);
			getchar();
		}
		scanf("%ld",&e);
		getchar();
		while(e--)
		{
			scanf("%s %s",n1,n2);
			getchar();
			for(i=0;i<std;i++)
			{
				if(!strcmp(n1,name[i]))
				{
					e1=i;
					break;
				}
			}
			for(i=0;i<std;i++)
			{
				if(!strcmp(n2,name[i]))
				{
					e2=i;
					break;
				}
			}
			enemy[e1][e2]=1;
			enemy[e2][e1]=1;
		}
		max=-1;
		for(i=0;i<std;i++)
		{
			for(j=i+1;j<std;j++)
			{
				if(enemy[i][j])
					continue;
				for(k=j+1;k<std;k++)
				{
					if(enemy[j][k] || enemy[i][k])
						continue;
					p=point[i]+point[j]+point[k];
					printf("%ld\n",p);
					if(p>max)
					{
						max=p;
						loc1=i;  loc2=j;  loc3=k;
					}
				}
			}
		}
		if(max==-1)
			printf("No team is possible\n");
		else
		{
			if(strcmp(name[loc1],name[loc2])>0)
			{
				temp=loc1;
				loc1=loc2;
				loc2=temp;
			}
			if(strcmp(name[loc2],name[loc3])>0)
			{	
				temp=loc2;
				loc2=loc3;
				loc3=temp;
			}
			if(strcmp(name[loc1],name[loc2])>0)
			{
				temp=loc1;
				loc1=loc2;
				loc2=temp;
			}
	
			printf("Case%ld:\n%s\n%s\n%s\n",t,name[loc1],name[loc2],name[loc3]);
		}
	}
	return 0;
}

			

