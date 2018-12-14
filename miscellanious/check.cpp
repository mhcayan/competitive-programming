#include<stdio.h>
int main()
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
		else if(m>5)
			p=5;
		else
			p=8;
		if(n<3)
			q=2;
		else if(n>5)
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
