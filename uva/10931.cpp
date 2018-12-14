#include<stdio.h>
int main()
{
	char a[100],b[100];
	long I,one,i,j,n;
	while(1)
	{
		scanf("%ld",&I);
		if(I==0)
			break;
		n=I;
		one=0;
		i=-1;
		while(n)
		{
			i++;
			a[i]=(n%2)+'0';
			if(a[i]=='1')
				one++;
			n=n/2;
		}
		for(j=0;j<=i;j++)
			b[j]=a[i-j];
		b[j]='\0';
		printf("The parity of %s is %d (mod 2).\n",b,one);
	}
	return 0;
}


