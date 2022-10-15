#include<iostream>
using namespace std;
int main()
{int no;
cout<<"Enter number of processes\n";
cin>>no;
int at[no],bt[no],wt[no],tat[no],pr[no],i,ct[no];
float avgwt=0,avgtat=0;
cout<<"Enter burst time\n";
for(i=0;i<no;i++)
{   pr[i]=i+1;
    cout<<"Process["<<i+1<<"]: ";
    cin>>bt[i];
}
cout<<"Enter arrival time\n";
for(i=0;i<no;i++){
    cout<<"Process["<<i+1<<"]: ";
    cin>>at[i];}
cout<<"PROCESS\tBURST TIME\tARRIVAL TIME\n";
    for(i=0;i<no;i++)
cout<<"P["<<pr[i]<<"]\t"<<bt[i]<<"\t\t  "<<at[i]<<"\n";
 for(int j=0;j<no;j++)
    {
        for(i=0;i<no;i++)
   {
        if(at[i]>at[i+1])
            {

               int temp=at[i];
               at[i]=at[i+1];
               at[i+1]=temp;

               temp=bt[i];
               bt[i]=bt[i+1];
               bt[i+1]=temp;

               temp=pr[i];
               pr[i]=pr[i+1];
               pr[i+1]=temp;
             }
   }
    }

cout<<"PROCESS\tBURST TIME\tARRIVAL TIME\n";
for(i=0;i<no;i++)
cout<<"P["<<pr[i]<<"]\t"<<bt[i]<<"\t\t  "<<at[i]<<"\n";
wt[0]=0;
tat[0]=bt[0];
ct[0]=bt[0]+at[0];
for(i=1;i<no;i++)
    {
        ct[i]=ct[i-1]+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
for(i=0;i<no;i++)
{
    avgwt=avgwt+wt[i];
    avgtat=avgtat+tat[i];

}
cout<<"PROCESS\tB T\tA T\tC T\tW T\tT A T\n";
for(i=0;i<no;i++)
{cout<<"P["<<pr[i]<<"]\t"<<bt[i]<<"\t"<<at[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";}
cout<<"Average waiting time is="<<avgwt/no<<" milliseconds";
cout<<"\nAverage turn around time is="<<avgtat/no<<" milliseconds";
return 0;
}
