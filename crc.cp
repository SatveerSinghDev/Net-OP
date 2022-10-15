#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter the size of the generator\n";
	cin>>n;
	int k=0;
	int gen[n];int rem[n];
	cout<<"enter the data\n";
	for(int i=0;i<n;i++)
	{
		cin>>gen[i];
	}
	int m;
	cout<<"enter the size of the frame\n";
	cin>>m;
	int div[m];
	int frame[m+n];
	int temp[m+n];
	cout<<"enter the frame\n";
	for(int i=0;i<m;i++)
	{
		cin>>frame[i];
	}
	cout<<"\nGenerator\n";
	for(int i=0;i<n;i++)
	{
		cout<<gen[i];
	}
	cout<<"\nFrame\n";
	for(int i=0;i<m;i++)
	{
		cout<<frame[i];
	}
	for(int i=0;i<m;i++)
	{
		temp[i]=frame[i];
	}
	int z=n-1;
	cout<<"\nNumber of zero's to be appended\n"<<z<<endl;
	for(int i=m;i<m+z;i++)
	{
		temp[i]=0;
	}
	cout<<"Data after appending zero's\n";
	for(int i=0;i<m+z;i++)
	{
		cout<<temp[i];
	}
	cout<<endl;
	if(frame[0]==1)
	{
		for(int i=0;i<n;i++)
		{
		    if(temp[i]==gen[i])
            {
                div[i]=0;
            }
            else
            {
                div[i]=1;
            }
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			div[i]=temp[i];
		}
	}
	if(m>n)
    {
	for(int i=0;i<=n+1;i++)
	{
	    k=0;
	if(div[i+1]==1)
	{
	    div[n+i]=temp[n+i];
		for(int j=1;j<n+1;j++)
		{

			if(div[j+i]==gen[k])
            {
                div[j+i]=0;
                k++;
            }
            else
            {
                div[j+i]=1;
                k++;
            }
		}
	}
	else
	{
	    div[n+i]=temp[n+i];
		for(int j=1;j<n+1;j++)
		{
		div[j+i]=div[j+i];
	}
	}
}
cout<<"the remainder is\n";
	for(int i=m;i<m+z;i++)
			cout<<div[i];
		}

  else
    {
      for(int i=0;i<n;i++)
	{
	    k=0;
	if(div[i+1]==1)
	{
	    div[n+i]=temp[n+i];
		for(int j=1;j<n+1;j++)
		{

			if(div[j+i]==gen[k])
            {
                div[j+i]=0;
                k++;
            }
            else
            {
                div[j+i]=1;
                k++;
            }
		}
	}
	else
	{
	    div[n+i]=temp[n+i];
		for(int j=1;j<n+1;j++)
		{
		div[j+i]=div[j+i];
	}
	}
	cout<<"the remainder is\n";
	for(int i=m;i<m+z;i++)
			cout<<div[i];
		}
}
    }




