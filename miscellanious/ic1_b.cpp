#include<stdio.h>
int main()
{
	char a[30][30],b[30][30];
	long m,n,k,t,c,p,q,i,j;
	scanf("%ld",&c);
	getchar();
	for(t=1;t<=c;t++)
	{
		scanf("%ld %ld %ld",&n,&m,&k);
		getchar();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%c",&a[i][j]);
			}
			getchar();
		}
		k=k%4;
		while(k--)
		{
			p=q=1;
			for(i=m;i>0;i--)
			{
				for(j=1;j<=n;j++)
				{
					b[p][q]=a[j][i];
					if(q==n)
						q=0;
					q++;
				}
				if(p==m)
					p=0;
				p++;
			}
			p=m;
			m=n;
			n=p;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
					a[i][j]=b[i][j];
			}
		}
		printf("Case: %ld\n",t);
	    for(i=1;i<=n;i++)
		{
		    for(j=1;j<=m;j++)
			{
				printf("%c",a[i][j]);
			}
		    printf("\n");
		}
		
	}
	return 0;
}
