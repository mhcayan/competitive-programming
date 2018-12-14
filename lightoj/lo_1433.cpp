#include<stdio.h>
#include<math.h>
int main()
{
    int cas,tc;
    double ox,oy,ax,ay,bx,by,ab,O,r;
    scanf("%d",&cas);
    for(tc=1;tc<=cas;tc++)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&ox,&oy,&ax,&ay,&bx,&by);
        r=sqrt((ax-ox)*(ax-ox)+(ay-oy)*(ay-oy));
        ab=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
        O=acos((2*r*r-ab*ab)/(2*r*r));
        if(O>180)
            O=360-O;
        printf("Case %d: %lf\n",tc,r*O);
    }
    return 0;
}
