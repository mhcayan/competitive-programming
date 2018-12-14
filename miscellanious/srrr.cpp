#include<iostream.h>
#include<stdio.h>
int i,j,k,l,x,y,z,m,n,mx;
int r1,c1,r2,c2,v;
double min[100],R1[100][100],R2[100][100];

int max(int z,int x)
{
	j=0;
	for(y=0;y<c1;y++)
	{
		if(R1[x][y]<R2[y][z])
			min[j++]=R1[x][y];
		else
			min[j++]=R2[y][z];
	}
	mx=0;
	for(i=0;i<5;i++)
	{
		if(min[i]>mx)
		{
			mx=min[i];
		}
	}
	cout<<mx<<" ";
	return mx;
}
int main()
{
	double R[100][100];
	cout<<"Enter the ROW & COLUMN No. for 1st matrix : "<<endl;
	cin>>r1>>c1;
	cout<<"Enter matrix values : "<<endl;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			cin>>R1[i][j];
		}
		cout<<endl;
	}
	cout<<"Enter the ROW & COLUMN No. for 2nd matrix : "<<endl;
	cin>>r2>>c2;
	cout<<"Enter matrix values : "<<endl;
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			cin>>R2[i][j];
		}
		cout<<endl;
	}


	for(z=0;z<r1;z++)
	{
		for(x=0;x<c2;x++)
		{
			v=max(z,x);
			R[z][x]=v;
		}
	}
    
	cout<<"The new matrix is : "<<endl;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			cout<<R[i][j]<<" ";
		}
		cout<<endl;
	}
   /* for(i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			cout<<R1[i][j]<<" ";
		}
		cout<<endl;
	}*/
	return 0;

}



