#include<iostream>
using namespace std;
int main()
{int n;
cout<<"Enter number of processes\n";
cin>>n;
int quantum=20,at[n],bt[n],wt[n],tat[n],pr[n],i,rem_bt[n];
float avgwt=0,avgtat=0;
cout<<"Enter burst time\n";
for(i=0;i<n;i++)
{   pr[i]=i+1;
    cin>>bt[i];
    rem_bt[i]=bt[i];
}
cout<<"Enter arrival time";
for(i=0;i<n;i++)
cin>>at[i];
cout<<"PROCESS\tBURST TIME\tARRIVAL TIME\tREMAINING TIME\n";
    for(i=0;i<n;i++)
cout<<"P["<<pr[i]<<"]\t"<<bt[i]<<"\t\t  "<<at[i]<<"\t\t  "<<rem_bt[i]<<"\n";
for(int j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
   {
        if(at[i]>at[i+1])
            {

               int temp=at[i];
               at[i]=at[i+1];
               at[i+1]=temp;

               temp=bt[i];
               bt[i]=bt[i+1];
               bt[i+1]=temp;


               temp=rem_bt[i];
               rem_bt[i]=rem_bt[i+1];
               rem_bt[i+1]=temp;

               temp=pr[i];
               pr[i]=pr[i+1];
               pr[i+1]=temp;

             }
   }
}
cout<<"PROCESS\tBURST TIME\tARRIVAL TIME\tREMAINING TIME\n";
    for(i=0;i<n;i++)
cout<<"P["<<pr[i]<<"]\t"<<bt[i]<<"\t\t  "<<at[i]<<"\t\t  "<<rem_bt[i]<<"\n";

 int t = 0;
while (true)
{
    int flag = 1;
    for (int i = 0 ; i < n; i++)
    {
        if (rem_bt[i] > 0)
        {
            flag = 0;
            if (rem_bt[i] > quantum)
            {
                t += quantum;
                rem_bt[i] -= quantum;
            }
            else
            {
                t = t + rem_bt[i];
                wt[i] = t - bt[i];
                rem_bt[i] = 0;
            }
        }
    }
    if (flag == 1)
        break;
}
     for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
     for(i=0;i<n;i++)
     {
        avgwt=avgwt+wt[i];
        avgtat=avgtat+tat[i];
     }
cout<<"PROCESS\tB T\tA T\tW T\tT A T\tR T\n";
for(i=0;i<n;i++)
{cout<<"P["<<pr[i]<<"]\t"<<bt[i]<<"\t"<<at[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<rem_bt[i]<<"\n";}
cout<<"Average waiting time is="<<avgwt/n<<" milliseconds";
cout<<"\nAverage turn around time is="<<avgtat/n<<" milliseconds";
return 0;
}


