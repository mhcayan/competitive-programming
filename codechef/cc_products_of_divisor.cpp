#include<stdio.h>
#include<math.h>
bool flag[10000];
long pr[1000];
bool f;
void sieve(long n)
{
	long c,i,j,m;
	pr[0]=2;
	c=1;
	m=sqrt(n);
	for(i=3;i<=m;i+=2)
	{	
		if(flag[i]==0)
		{
			pr[c++]=i;
			for(j=i*i;j<=n;j+=i+i)
				flag[j]=1;
		}
	}
	for(;i<=n;i+=2)
	{
		if(flag[i]==0)
			pr[c++]=i;
	}
}
long sqr(long p)
{
	return p*p;
}
long bm(long b,long p,long m)
{
	if(p==0)
		return 1;
	if(p%2==0)
        return sqr(bm(b,p/2,m))%m;
	else
		return ((b%m)*bm(b,p-1,m))%m;
}
int main()
{
	long t,i,m,n,M,N,d,div,res;
	sieve(800);
	scanf("%ld",&t);
	long cas=1;
	while(t--)
	{
		scanf("%ld",&n);
		printf("case %ld: ",cas++);
		f=0;
		m=sqrt(n);
		N=n;
		M=m;
		d=1;
		for(i=0;pr[i]<=m;i++)
		{
			if(n%pr[i]==0)
			{
				div=1;
				while(n%pr[i]==0)
				{
					n/=pr[i];
					div++;
				}
				d*=div;
				m=sqrt(n);
			}
		}
		if(n>1)
			d*=2;
		//printf("%ld\n",d);
		if(M*M==N)
		{
			if(N==1)
				printf("1\n");
			else
			{
				d=(d-3)/2;
				if(N>999 || (N>31 && d>1) || (N>9 && d>2))
			        f=1;
			    else
				{
					res=M;
					for(i=0;i<d;i++)
					{
						res*=N;
						if(res>=1000)
						{
							f=1;
							break;
						}
					}
					if(res>=10000)
						f=1;
				}
			    if(f)
				{
					res=(bm(N,d,10000)*M)%10000;
			        printf("%04ld\n",res);
				}
				else
					printf("%ld\n",res);
			    
			}
		}
		else
		{
			d=(d-2)/2;
			if(N>999 || (N>31 && d>1) || (N>9 && d>2))
			        f=1;
			else
			{
				res=1;
				for(i=0;i<d;i++)
				{
					res*=N;
					if(res>=1000)
					{
						f=1;
						break;
					}
				}
			}
			if(f)
			{
			    res=bm(N,d,10000);
			    printf("%04ld\n",res);
			}
			else
				printf("%ld\n",res);
		}
	}
	return 0;
}
