#include<stdio.h>
int main()
{
	int a[10][10];
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			scanf("%d",&a[i][j]);
			b[i][j]=a[i][j];
		}
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			while(a[i][j]==0)
			{
				v=check(b[i][j],i,j);
				if(v<=9)
				{
					b[i][j]=v;
				}
				else
					backtrack(i,j);
			}
		}
	}
	return 0;
}
int check(int v;int m,int n);
{
	for(v++;v<10;v++)
	{
		for(j=n+1;j<9;j++)
		{
			if(v==b[m][j])
				break;
		}
		for(j=n-1;j>=0;j--)
		{
			if(v==b[m][j])
				break;
		}
		for(i=0;i>m;i++)
		{
			if(v==b[i][n])
				break;
		}
		for(i=m+1;i<9;i++)
		{
			if(v==b[i][n])
				break;
		}
		if(m<3)
			p=2;
		else if(m<6)
			p=5;
		else
			p=8;
		if(n<3)
			q=2;
		else if(n<6)
			q=5;
		else
			q=8;
		for(i=p-2;i<=p;i++)
		{
			for(j=q-2;j<=q;j++)
			{
				if(i!=m && j!=n)
				{
					if(v==b[i][j])
					{
						flag=1;
						break;
					}
				}
			}
			if(flag)
				break;
		}
	}
	return v;
}
