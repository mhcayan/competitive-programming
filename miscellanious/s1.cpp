#include<iostream.h>
int main()
{
    char process[100];
    int brst[100];
    int o[100];
    int w[100];
    int t[100];
    brst[0]=0;
    int n,i,awt,att;
    att=0;
    awt=0;
    cin>>n;
    
    for(i=1;i<=n;i++)
    {
        cout<<"\n Enter the process:";
        cin>>process[i];
     }
    for(i=1;i<=n;i++)
    {
        cout<<"\n Enter the burst time:";
        cin>>brst[i];
     }
     o[0]=0;
     for(i=1;i<=n;i++)
     {
         cout<<"\n Enter the order:";
         cin>>o[i];
      }
      w[0]=0;
     for(i=1;i<=n;i++)
     {
        w[0]=0;
        w[i]=w[i-1]+brst[o[i-1]];
        cout<<"\n waiting time for process:"<<process[o[i]]<<"=";
        cout<<w[i];
      }
     for(i=1;i<=n;i++)
           awt=awt+w[i];
     
      cout<<"\n Average waiting time:"<<awt/n;
      t[0]=0;
      for(i=1;i<=n;i++)
     {
         t[o[i]]=w[i]+brst[o[i]];
         cout<<"\n turned arround time:"<<process[o[i]]<<"=";
         cout<<t[o[i]];
     }
     for(i=1;i<=n;i++)
         att=att+t[o[i]];
     cout<<"\n Average turned arround time:"<<att/3;
   return 0;
}