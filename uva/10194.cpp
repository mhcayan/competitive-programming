#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tag{
	char name[50];
	int point,gp,w,t,l,gd,gs,ga;
}soccer;
int cmp_str(char a[100],char b[100])
{
    int i;
	for(i=0;a[i] && b[i];i++)
	{
		if(a[i]>='A' && a[i]<='Z')
			a[i]=a[i]+32;
		if(b[i]>='A' && b[i]<='Z')
			b[i]=b[i]+32;
		if(a[i]>b[i])
			return 1;
		else if(a[i]<b[i])
			return -1;
	}
	if(a[i]=='\0' && b[i]=='\0')
		return 0;
	else if(b[i]=='\0')
		return 1;
	else 
		return -1;
}
int cmp(const void *a,const void *b)
{
	soccer *x=(soccer *)a;
	soccer *y=(soccer *)b;
	if(x->point!=y->point)
		return y->point-x->point;
	else if(x->w!=y->w)
		return y->w-x->w;
	else if(x->gd!=y->gd)
		return y->gd-x->gd;
	else if(x->gs!=y->gs)
		return y->gs-x->gs;
	else if(x->gp!=y->gp)
		return x->gp-y->gp;
	else
		return cmp_str(x->name,y->name);
}
int main()
{
	soccer team[35];
	int test,i,T,G,g1,g2,j,k;
	char tournament[150],str[200],t1[50],t2[50],p[50],q[50];
	scanf("%d",&test);
	getchar();
	while(test--)
	{
		gets(tournament);
		scanf("%d",&T);
		getchar();
		for(i=0;i<T;i++)
		{
			team[i].point=0;team[i].gp=0;team[i].w=0;team[i].t=0;team[i].l=0;team[i].gd=0;team[i].gs=0;team[i].ga=0;
		}
		for(i=0;i<T;i++)
			gets(team[i].name);
		scanf("%d",&G);
		getchar();
		for(j=0;j<G;j++)
		{
			gets(str);
			k=0;
			for(i=0;str[i]!='#';i++)
				t1[k++]=str[i];
			t1[k]='\0';
			k=0;
			for(i++;str[i]!='@';i++)
				p[k++]=str[i];
			p[k]='\0';
			g1=atoi(p);
			k=0;
			for(i++;str[i]!='#';i++)
				q[k++]=str[i];
			q[k]='\0';
			g2=atoi(q);
			k=0;
			for(i++;str[i];i++)
				t2[k++]=str[i];
			t2[k]='\0';
			for(i=0;i<T;i++)
			{
				if(strcmp(team[i].name,t1)==0)
				{
			    	team[i].gp++;
					team[i].gs+=g1;
					team[i].ga+=g2;
					team[i].gd+=g1-g2;
					if(g1>g2)
					{
						team[i].w++;
						team[i].point+=3;
					}
					else if(g1<g2)
						team[i].l++;
					else
					{
						team[i].t++;
						team[i].point++;
					}
				}
			}
			for(i=0;i<T;i++)
			{
				if(strcmp(team[i].name,t2)==0)
				{
			    	team[i].gp++;
					team[i].gs+=g2;
					team[i].ga+=g1;
					team[i].gd+=g2-g1;
					if(g2>g1)
					{
						team[i].w++;
						team[i].point+=3;
					}
					else if(g2<g1)
						team[i].l++;
					else
					{
						team[i].t++;
						team[i].point++;
					}
				}
			}
		}
		qsort(team,T,sizeof(soccer),cmp);
		printf("\n%s\n",tournament);
		for(i=0;i<T;i++)
		{
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,team[i].name,team[i].point,team[i].gp,team[i].w,
				team[i].t,team[i].l,team[i].gd,team[i].gs,team[i].ga);
		}
		if(test)
		    printf("\n");
	}
	return 0;
}
