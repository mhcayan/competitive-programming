#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ca=0,p,q,r,i,f;
	char e[10],o,a[3],b[3],c[3];
	while(gets(e))
	{
		f=p=q=r=0;
		for(i=0;e[i]!='\0';i++)
		{
			if(e[i]=='+'||e[i]=='-')
			{
				f=1;
				o=e[i];
				continue;
			}
			if(e[i]=='=')
			{
				f=2;
				continue;
			}
			
    		if(f==0)
			{
				a[p]=e[i];
			    p++;
			}
	    	else if(f==1)
			{
				b[q]=e[i];
			    q++;
			}
		    else
			{
	      	    c[r]=e[i];
				r++;
			}
		}
	    a[p]=b[q]=c[r]='\0';
	    p=atoi(a);
	    q=atoi(b);
	    r=atoi(c);
	    if(o=='+')
		    p=p+q;
	    else
		    p=p-q;
	    if(c[r-1]!='?')
		{
		    if(p==r)
		        ca++;
		}
 
	}
	printf("%d\n",ca);
	return 0;
}
			




	

