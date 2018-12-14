#include<stdio.h>
#include<math.h>
int main()
{
	long flag,l1,l2,i,j,max1,max2,a[50],b[50],sum,k;
	char s1[100],s2[100],str[200];
	while(gets(str))
	{
		sscanf(str,"%s %s",s1,s2);
		i=j=0;
		max1=s1[0];
		for(i=1;s1[i];i++)             //DETERMINING THE DIGIT WHICH HAS MAX VALUE IN S1
		{
			if(s1[i]>max1)
				max1=s1[i];
		}
		if(max1>='0'&&max1<='9')
			max1=max1-'0';
		else
			max1=max1-55;
		l1=i-1;
		max2=s2[0];
		for(i=1;s2[i];i++)            //DETERMINING THE DIGIT WHICH HAS MAX VALUE IN S2     
		{
			if(s2[i]>max2)
				max2=s2[i];
		}
		if(max2>='0' && max2<='9')
			max2=max2-'0';
		else
			max2=max2-55;
		l2=i-1;
		if(max1==0)
			max1=1;
		if(max2==0)
			max2=1;
		for(i=max1+1;i<37;i++)           //CONVERTING S1 IN ALL BASES //a[k] keeps the value of s1 in base k..
		{
			k=l1;
			sum=0;
			for(j=0;s1[j];j++)
			{
				if(s1[j]>='0' && s1[j]<='9')
					sum+=(s1[j]-'0')*pow(i,k);
				else
					sum+=(s1[j]-55)*pow(i,k);
				k--;;
			}
			a[i]=sum;
		}
		for(i=max2+1;i<37;i++)           //CONVERTING S2 IN ALL BASES 
		{
			k=l2;
			sum=0;
			for(j=0;s2[j];j++)
			{
				if(s2[j]>='0'&&s2[j]<='9')
					sum+=(s2[j]-'0')*pow(i,k);
				else
					sum+=(s2[j]-55)*pow(i,k);
				k--;
			}
			b[i]=sum;
		}
		flag=1;
		for(i=max1+1;i<37;i++)
		{
			for(j=max2+1;j<37;j++)
			{
				if(a[i]==b[j])
				{
					printf("%s (base %ld) = %s (base %ld)\n",s1,i,s2,j);
					flag=0;
					break;
				}
			}
            if(flag==0)
				break;
		}
		if(flag)
			printf("%s is not equal to %s in any base 2..36\n",s1,s2);
	
	}
	return 0;
}




