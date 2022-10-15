#include<iostream>
using namespace std;


int main()
{
	int p[10],rt[10],bt[10],tat[10],at[10],wt[10],pr[10];
	int tbt=0;
	int n;
	float avwt=0,avtat=0;
	cout<<"enter the no. of processes";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		p[i]=i+1;
	}
	cout<<"enter the arrival time of processes";
	for(int i=0;i<n;i++)
	cin>>at[i];
	cout<<"enter the burst time of processes";
	for(int i=0;i<n;i++)
	{

	cin>>bt[i];
	rt[i]=bt[i];
	tbt=tbt+bt[i];

	}
	cout<<"enter the priority of processes";
	for(int i=0;i<n;i++)
	cin>>pr[i];
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(pr[i]>pr[max])
		max=i;
	}
	for(int time=0;time<=tbt;)
	{
		for(int i=0;i<n;i++)

			if(rt[i]>0 && at[i]<=time && pr[i]<pr[max])
			max=i;
			rt[max]--;
			time++;

		if(rt[max]==0)
		{
			wt[max]=time-at[max]-bt[max];
			tat[max]=time-at[max];
			for(int i=0;i<n;i++)
			if(pr[i]>pr[max])
			max=i;

		}
	}

		cout<<"\nprocess\t\tburst time\tpriority\twaiting time\tturnaround time\n";
		for(int i=0;i<n;i++)
		{
			avwt+=wt[i];
			avtat+=tat[i];
			cout<<"\n"<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<pr[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
		}
			avwt/=n;
			avtat/=n;
			cout<<"average waiting time:"<<avwt;
			cout<<"average turnaround time:"<<avtat;

	}
