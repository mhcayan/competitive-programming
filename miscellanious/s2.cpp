#include<iostream.h>
int main()
{
  char process[100];
  int brst[100],o[100],wt[100],tt[100];
  int n,i,awt,att,t,t1,j;
  brst[0]=0;
  awt=0;
  att=0;
  cout<<"Enter the number of process:";
  cin>>n;
  for(i=1;i<=n;i++)
  {
   cout<<"\nEnter the process:";
   cin>>process[i];
  }
  for(i=1;i<=n;i++)
  {
   cout<<"\nThe burst time:";
   cin>>brst[i];
  }


  for(i=1;i<=n;i++)
  {
  for(j=1;j<=n-i;j++)
  {
    if(brst[j]>brst[j+1])
    {
    t=brst[j+1];
    t1=process[j+1];
    brst[j+1]=brst[j];
    process[j+1]=process[j];
    brst[j]=t;
    process[j]=t1;
    }
    }
    }
    for(i=1;i<=n;i++)
    cout<<"After processing:"<<brst[i]<<"="<<process[i]<<"\n";

    for(i=1;i<=n;i++)

  {
   wt[0]=0;
   wt[i]=wt[i-1]+brst[i-1];
   cout<<"\nWaiting time for process: "<<process[i]<<"=";
   cout<<wt[i];
  }
  for(i=1;i<=n;i++)
  awt=awt+wt[i];
  cout<<"\nAverage waiting time: "<<awt/n;
  tt[0]=0;
  for(i=1;i<=n;i++)
  {
   tt[i]=wt[i]+brst[i];
   cout<<"\nTurned around time: "<<process[i]<<"=";
   cout<<tt[i];
  }
  for(i=1;i<=n;i++)
  att=att+tt[i];
  cout<<"\nAverage turned around time: "<<att/n;
return 0;
}