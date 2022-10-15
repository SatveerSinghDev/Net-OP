#include<iostream>
#include<iomanip>
using namespace std;
int main()
{

    int at[10],pid[10],bt[10];
    int n;

    cout<<"How many process to be entered : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter burst time  of "<<i+1<<" process : ";
        cin>>bt[i];
        cout<<"enter the arrival time of process"<<i+1<<"=";
        cin>>at[i];
        pid[i]=i+1;
    }



    cout<<endl<<"Process ID\tBurst time\tArrival Time "<<endl;
    for(int i=0;i<n;i++)
        cout<<pid[i]<<"\t\t"<<bt[i]<<"\t\t"<<at[i]<<endl;



    int temp;
    for(int y=0;y<n-1;y++)
    {
        for(int z=0;z<n-1;z++)
            if(at[z]>at[z+1])
            {
                temp=at[z];
                at[z]=at[z+1];
                at[z+1]=temp;
                temp=pid[z];
                pid[z]=pid[z+1];
                pid[z+1]=temp;
                temp=bt[z];
                bt[z]=bt[z+1];
                bt[z+1]=temp;
            }
    }

    int rt[10],flag=1;
 int ar=0,pos,wt,tnt,min,max=bt[0];
 float avg=0,avtnt=0;
 for(int i=0;i<n;i++)
 {
    rt[i]=bt[i];
    if(max<bt[i])
       max=bt[i];
 }
    ar=at[0];
    min=max+1;
 cout<<"\nProcess ID \tWaiting time \tTurn Around time "<<endl;
 while(flag)
    {
        for(int i=0;i<n;i++)
        {
            if(ar>=at[i]&&min>bt[i]&&pid[i]>0)
            {
                pos=i;
         min=bt[i];
     }
    }
        ar++;
        bt[pos]--;
        min=max+1;
        if(bt[pos]==0)
        {
            wt=ar-rt[pos]-at[pos];
     tnt=ar-at[pos];
     cout<<pid[pos]<<"\t\t"<<wt<<"\t\t"<<tnt<<endl;
     pid[pos]=-1;
     avg+=wt;
     avtnt+=tnt;
        }
        flag=0;
        for(int k=0;k<n;k++)
            if(pid[k]!=-1)
               flag=1;
    }
    avg=avg/(float)n;
    avtnt/=(float)n;
    cout<<"\nAverage Waiting time     : "<<avg;
    cout<<"\nAverage turn Around time : "<<avtnt<<endl;
}
