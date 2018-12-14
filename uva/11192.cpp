#include<stdio.h>
#include<string.h>
int main()
{
	char a[120],b[120];
	int g,l,gl,i,j,beg,end;
	while(scanf("%d",&g))
	{

		if(g==0)
			break;
		scanf("%s",a);
		l=strlen(a);
		gl=l/g;
		j=0;
		beg=0;
		end=gl-1;
		while(beg<l)
		{
			for(i=end;i>=beg;i--)
				b[j++]=a[i];
			beg=end+1;
			end=beg+gl-1;
		}
		b[l]='\0';
	    printf("%s\n",b);
	}
	return 0;
}
