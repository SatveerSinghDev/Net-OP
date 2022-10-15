#include <iostream>
using namespace std;

int main()
{
    int burst_time[20],ct[20],at[20],process[20],waiting_time[20],tat[20],i,j,n,total=0,pos,temp;
    float wait_avg=0.0,TAT_avg=0.0;
    cout<<"Enter number of process:";
    cin>>n;
    cout<<"Enter arrival time(in sorted order): \n";
    for(i=0;i<n;i++){
        cout<<"Process["<<i+1<<"]: ";
        cin>>at[i];}
    cout<<"\nEnter Burst time: \n";
    for(i=0;i<n;i++)
    {
       cout<<"Process["<<i+1<<"]: ";
       cin>>burst_time[i];
        process[i]=i+1;           //Process Number
    }

//Sorting
       for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }

        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;

        temp=at[i];
        at[i]=at[pos];
        at[pos]=temp;

        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }

    //First process has 0 waiting time
    waiting_time[0]=0;
    ct[0]=waiting_time[0]+burst_time[0];
    tat[0]=burst_time[0];

    //calculate waiting time
    for(i=1;i<n;i++)
    {
        ct[i]=ct[i-1]+burst_time[i];
        tat[i]=ct[i]-at[i];
        waiting_time[i]=tat[i]-burst_time[i];
    }

    for(i=0;i<n;i++)
    {//Calculating Average waiting time
      wait_avg=wait_avg+waiting_time[i];
      TAT_avg=TAT_avg+tat[i];
    }

    cout<<"PROCESS\tB T\tA T\tC T\tW T\tT A T\n";
for(i=0;i<n;i++)
{cout<<"P["<<process[i]<<"]\t"<<burst_time[i]<<"\t"<<at[i]<<"\t"<<ct[i]<<"\t"<<waiting_time[i]<<"\t"<<tat[i]<<"\n";}
cout<<"Average waiting time is="<<wait_avg/n<<" milliseconds";
cout<<"\nAverage turn around time is="<<TAT_avg/n<<" milliseconds";
return 0;
}
