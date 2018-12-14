#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int t,l,s,i,j,k;
	char a[11000],b[11000];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(a);
		l=strlen(a);
		s=sqrt(l);
		k=0;
		if(s*s==l)
		{
			for(i=0;i<s;i++)
			{
				for(j=0;j<s;j++)
					b[k++]=a[i+j*s];
			}
			b[k]='\0';
			printf("%s\n",b);
		}
		else
			printf("INVALID\n");
	}
	return 0;
}

