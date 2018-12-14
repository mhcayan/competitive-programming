#include<stdio.h>
void main()
{
int x,y,t;
scanf("%d %d",&x,&y);
t=x;
x=y;
y=t;
printf("%d %d",x,y);
}