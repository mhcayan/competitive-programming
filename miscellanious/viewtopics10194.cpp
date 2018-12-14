/* @JUDGE_ID: 16916** 10194 C++ "Naushad's Programming" */

/* "@BEGIN_OF_SOURCE_CODE" */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int strcmpti(char str1[], char str2[])
{
int i;
int len1 = strlen(str1);
int len2 = strlen(str2);
if(len1>len2)
{
for(i=0;i<len1;i++)
{
if(toupper(str1[i])>toupper(str2[i]))
return 1;
else if(toupper(str1[i])<toupper(str2[i]))
return -1;
else return 0;

}
}
else if(len2>len1)
{
for(i=0;i<len2;i++)
{
if(toupper(str2[i])>toupper(str1[i]))
return 1;
else if(toupper(str2[i])<toupper(str1[i]))
return -1;
else return 0;

}
}
else return 0;

}
struct TE
{
char Tname[31];
int Point;
int Win;
int Loss;
int Ties;
int Gdiff;
int Mgoal;
int Kgoal;
int Lply;
};
int compare(const void *a,const void *b)
{
int t;
t = ((TE*)b)->Point - ((TE*)a)->Point;
if(t!=0)return t;
t = ((TE*)b)->Win - ((TE*)a)->Win;
if(t!=0)return t;
t = ((TE*)b)->Gdiff - ((TE*)a)->Gdiff;
if(t!=0)return t;
t = ((TE*)b)->Mgoal - ((TE*)a)->Mgoal;
if(t!=0)return t;
t = ((TE*)a)->Lply - ((TE*)b)->Lply;
if(t!=0)return t;
t = strcmpti(((TE*)b)->Tname,((TE*)a)->Tname);
if(t!=0)return t;
}
int i;
struct TE Fifa[31];
int main()
{
int N;
char Ginfo[1000];
while(scanf("%d",&N)!=EOF)
{
while(N--)
{
char tour[100];
fflush(stdin);
gets(tour);
int T,dummy;
scanf("%d",&T);
dummy = T;
for(i=0;i<T;i++)
{
Fifa[i].Point=0;
Fifa[i].Win=0;
Fifa[i].Gdiff=0;
Fifa[i].Mgoal=0;
Fifa[i].Kgoal=0;
Fifa[i].Lply=0;
Fifa[i].Loss=0;
Fifa[i].Ties=0;
}
i=0;
fflush(stdin);
while(i!=dummy)
{
gets(Fifa[i++].Tname);
}
int G, kak;
scanf("%d",&G);
dummy = G;
while(dummy--)
{
char T1[31], T2[31];
int Tgo1, Tgo2;
fflush(stdin);
gets(Ginfo);
int len = strlen(Ginfo);
for(i=0;i<len;i++)
{
if(Ginfo[i]==' ')
Ginfo[i] = '@';
}

for(i=0;i<len;i++)
{
if(Ginfo[i]=='#')
Ginfo[i] = ' ';
}
char goru[30];
sscanf(Ginfo,"%s %s %s",&T1,&goru,&T2);
len = strlen(T1);
for(i=0;i<len;i++)
{
if(T1[i]=='@')
T1[i] = ' ';
}
len = strlen(T2);
for(i=0;i<len;i++)
{
if(T2[i]=='@')
T2[i] = ' ';
}
sscanf(goru,"%d@%d",&Tgo1,&Tgo2);
for(i=0;i<T;i++)
{
kak = strcmp(T1,Fifa[i].Tname);
if((!kak))
{
Fifa[i].Mgoal += Tgo1;
Fifa[i].Kgoal += Tgo2;
if(Tgo1>Tgo2)
{
Fifa[i].Point += 3;
Fifa[i].Win++;
Fifa[i].Lply++;
}
else if(Tgo1<Tgo2)
{
Fifa[i].Point += 0;
Fifa[i].Lply++;
Fifa[i].Loss++;
}
else
{
Fifa[i].Point += 1;
Fifa[i].Lply++;
Fifa[i].Ties++;
}
break;
}
}

for(i=0;i<T;i++)
{
kak = strcmp(T2,Fifa[i].Tname);
if(!(kak))
{
Fifa[i].Mgoal += Tgo2;
Fifa[i].Kgoal += Tgo1;
if(Tgo2>Tgo1)
{
Fifa[i].Point += 3;
Fifa[i].Win++;
Fifa[i].Lply++;
}
else if(Tgo2<Tgo1)
{
Fifa[i].Point += 0;
Fifa[i].Lply++;
Fifa[i].Loss++;
}
else
{
Fifa[i].Point += 1;
Fifa[i].Lply++;
Fifa[i].Ties++;
}
break;
}
}

}
for(i=0;i<T;i++)
Fifa[i].Gdiff = Fifa[i].Mgoal - Fifa[i].Kgoal;

printf("%s\n",tour);
fflush(stdin);
qsort((void*) Fifa, T, sizeof(Fifa[0]), compare);

for(i=0;i<T;i++)
{
printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,
Fifa[i].Tname, Fifa[i].Point,Fifa[i].Lply,Fifa[i].Win,Fifa[i].Ties,Fifa[i].Loss,
Fifa[i].Gdiff,Fifa[i].Mgoal,Fifa[i].Kgoal);
}
}
}
return 0;
}
