#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define S1(a) scanf("%d",&a)
#define S2(a,b) scanf("%d %d",&a,&b)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define mems(x,a) memset(x,a,sizeof(x))


char str[17][109];
int F[109],H[17][17],n,L[17],finalMask;
int M[17][(1<<16)+9],Called[17][(1<<16)+9];
bool TT[17][1<<16];

int cmpstr(void const *a, void const *b) 
{ 
    char const *aa = (char const *)a;
    char const *bb = (char const *)b;

    return strcmp(aa, bb);
}

int dp(int lastUsed,int mask)
{
  if(mask==finalMask) return 0;
  int &rs=M[lastUsed][mask];
  if(rs!=-1) return rs;
  
  int t1=INT_MX;
  int t,i;
  for(i=1;i<=n;i++)
   if(!(mask&(1<<(i-1))))
   {
     if(H[lastUsed][i]==L[i])
     {
      t=dp(lastUsed,mask|(1<<(i-1)));
      if(t1>t) t1=t,TT[lastUsed][mask]=1,Called[lastUsed][mask]=i-1;
     }
     else{
      t=L[i]-H[lastUsed][i]+dp(i,mask|(1<<(i-1)));
     if(t1>t)
      Called[lastUsed][mask]=i-1,t1=t,TT[lastUsed][mask]=0;}
   }

   return rs=t1;  
}
void print(int p,int lastUsed,int mask,bool on)
{
     int i;
     if(mask&&!on)
     {
       for(i=H[p][lastUsed];str[lastUsed][i];i++)
         printf("%c",str[lastUsed][i]);
     }
     if(mask==finalMask) return;
     if(TT[lastUsed][mask])
     print(lastUsed,lastUsed,mask|(1<<Called[lastUsed][mask]),1);
     else
     print(lastUsed,Called[lastUsed][mask]+1,mask|(1<<Called[lastUsed][mask]),0);
}
void Failure(int indx)
{
  int i,j;
  F[0]=0;
  i=1;
  j=0;
  while(str[indx][i])
  {
    if(str[indx][i]==str[indx][j]) 
     F[i]=j+1,i++,j++;
    else if(j>0)
     j=F[j-1];
    else
     j=0,i++;
  }
}
int KMP(int indxF,int indxO)
{
  int i,j;
  j=i=0;
  while(str[indxO][i])
  {
    if(str[indxO][i]==str[indxF][j])
    { 
       i++,j++;
       if(str[indxF][j]=='\0') return j;
    }
    else if(j>0)
    {
      j=F[j-1];
    }
    else
     j=0,i++;
  }
  return j;                   
}
int main()
{
    int kase,kas=0,i,j;
    S1(kase);
    while(kase--)
    {
      S1(n);
     
      for(i=1;i<=n;i++){
       scanf("%s",str[i]);
       }
       
       mems(M,-1);
       finalMask=(1<<n)-1;
       
       qsort(&str[1],n,sizeof(str[1]),cmpstr);
     
      for(i=1;i<=n;i++)
      {
       L[i]=strlen(str[i]);
       Failure(i);
       for(j=1;j<=n;j++)
        if(i!=j){
          H[j][i]=KMP(i,j);
          }
      }
     
        dp(0,0);
        printf("Case %d: ",++kas);
        print(0,0,0,0);
        printf("\n");
    }
 
    return 0;
}
