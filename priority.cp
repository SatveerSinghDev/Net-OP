#include<iostream>
using namespace std;
int main()
{int n;
cout<<"Enter number of processes\n";
cin>>n;
int ar[n],br[n],wt[n],tat[n],p[n],pr[n],ct[n],i,m=0,avg=0;
cout<<"Enter burst time\n";
for(i=0;i<n;i++)
{   p[i]=i+1;
    cin>>br[i];
}
cout<<"Enter arrival time\n";
for(i=0;i<n;i++)
cin>>ar[i];

cout<<"Enter priority\n";
for(i=0;i<n;i++)
cin>>pr[i];

cout<<"PROCESS\tBURST TIME\tARRIVAL TIME\tPRIORITY\n";
for(i=0;i<n;i++)
cout<<"P["<<p[i]<<"]\t"<<br[i]<<"\t\t  "<<ar[i]<<"\t\t  "<<pr[i]<<"\n";
int temp;
    for(int j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
   {
        if(pr[i]>pr[i+1])
            {
               temp=pr[i];
               pr[i]=pr[i+1];
               pr[i+1]=temp;

               temp=ar[i];
               ar[i]=ar[i+1];
               ar[i+1]=temp;

               temp=br[i];
               br[i]=br[i+1];
               br[i+1]=temp;

               temp=p[i];
               p[i]=p[i+1];
               p[i+1]=temp;
             }
   }
    }
cout<<"PROCESS\tBURST TIME\tARRIVAL TIME\tPRIORITY\n";
for(i=0;i<n;i++)
cout<<"P["<<p[i]<<"]\t"<<br[i]<<"\t\t  "<<ar[i]<<"\t\t  "<<pr[i]<<"\n";
wt[0]=0;
tat[0]=br[0];
ct[0]=br[0]+ar[0];
for(i=1;i<n;i++)
    {
        ct[i]=ct[i-1]+br[i];
        tat[i]=ct[i]-ar[i];
        wt[i]=tat[i]-br[i];
    }
for(i=0;i<n;i++)
{
    m=m+wt[i];
    avg=avg+tat[i];

}
cout<<"PROCESS\tB T\tA T\tC T\tW T\tT A T\tPRIORITY\n";
for(i=0;i<n;i++)
{cout<<"P["<<p[i]<<"]\t"<<br[i]<<"\t"<<ar[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<pr[i]<<"\n";}
cout<<"Average waiting time is="<<m/n<<"seconds";
cout<<"\nAverage turn around time is="<<avg/n<<"seconds";

return 0;
}
