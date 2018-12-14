#include<stdio.h>
int dir(int x1,int y1,int x2,int y2,int x3,int y3);
int max(int a,int b);
int min(int a,int b);
int intersect(int x1,int x2, int x3,int x4,int y1,int y2,int y3,int y4);
int main()
{
	int x1,x2,x3,x4,y1,y2,y3,y4,ans;
	while(1)
	{
		printf("Enter the two end point of the first line(enter x1=0 & y1=0 to exit)\n");
	    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(x1==0&&y1==0)
			break;
	    printf("Enter the two end point of the second line\n");
	    scanf("%d %d %d %d",&x3,&y3,&x4,&y4);
	    ans=intersect(x1,x2,x3,x4,y1,y2,y3,y4);
	    if(ans)
			printf("Yes\n");
	    else
		    printf("No\n");
	}
	return 0;
}
int intersect(int x1,int x2, int x3,int x4,int y1,int y2,int y3,int y4)
{
	int d1,d2,d3,d4;
	d1=dir(x1,y1,x2,y2,x3,y3);
	d2=dir(x1,y1,x2,y2,x4,y4);
	d3=dir(x3,y3,x4,y4,x1,y1);
	d4=dir(x3,y3,x4,y4,x2,y2);
	if(((d1>0 && d2<0)||(d1<0 && d2>0))&&((d3>0 && d4<0) || (d3<0 && d4>0)))
		return 1;
	else if(d1==0)
	{
		if((x3>=min(x1,x2)&&x3<=max(x1,x2)) && y3>=min(y1,y2)&&y3<=max(y1,y2))
			return 1;
		else 
			return 0;
	}
	else if(d2==0)
	{
		if((x4>=min(x1,x2)&&x4<=max(x1,x2)) && y4>=min(y1,y2)&&y4<=max(y1,y2))
			return 1;
		else 
			return 0;
	}	
	else if(d3==0)
	{
		if((x1>=min(x3,x4)&&x1<=max(x3,x4)) && y1>=min(y3,y4)&&y1<=max(y3,y4))
			return 1;
		else
			return 0;
	}
	else if(d4==0)
	{
		if((x2>=min(x3,x4)&&x2<=max(x3,x4)) && y2>=min(y3,y4)&&y2<=max(y3,y4))
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
int max(int a,int b)
{
	if(a>=b)
		return a;
	else 
		return b;
}
int min(int a,int b)
{
	if(a>=b)
		return a;
	else 
		return b;
}
int dir(int x1,int y1,int x2,int y2,int x3,int y3)
{

	return ((x3-x1)*(y2-y2)-(y3-y1)*(x2-x1));
}


	




	
