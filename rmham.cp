#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no of dataword bits";
    cin>>n;
    int ar[n];
    cout<<"Enter dataword";
    for(int i=0;i<n;i++){
    cin>>ar[i];}
    int r=1;int flag=1;
    while(n+r+1>pow(2,r)){
            r++;
    }
    cout<<"no of redundant bits are:"<<r<<endl;
    int a[20],temp[n+r];int p=0,k=0;int z=n+r;
    for(int i=0;i<n+r;i++)
    {
        if(i==pow(2,p)-1)
        {
            a[i]=0;
            p++;
        }
        else
        {
            a[i]=ar[k++];
        }
    }
    cout<<"Dataword now"<<endl;
    for(int i=0;i<n+r;i++)
    {
        temp[i]=a[i];
        cout<<a[i];
    }
    for(int i=0;i<r;i++)
    {
        int count=0;
        int pos=(int)pow(2,i);
        int parity=pos-1;
        while(parity<n+r)
        {
            for(int j=parity;j<parity+pos;j++)
            {
                if(a[j]==1)
                    count++;
            }
            parity=parity+2*pos;
        }
        if(count%2==0)
            a[pos-1]=0;
        else
            a[pos-1]=1;

    }
    cout<<"\nupdated codeword\n";
    for(int i=0;i<n+r;i++)
    {
        cout<<a[i];
    }
    int arr[r];int s=0;
    for(int i=0;i<r;i++)
    {
            arr[i]=a[(int)pow(2,s)-1];
            s++;
    }
    cout<<"\ndata\n";
    for(int i=0;i<r;i++)
    {
        cout<<arr[i];
    }/*
    int sum=0;int j=0;
    for(int i=r-1;i>=0;i--)
    {
        sum=sum+(arr[i]*(int)pow(2,j));
        j++;
    }
    cout<<endl<<sum<<endl;
    if(sum!=0)
    {
        cout<<"\nData incorrect\n";
    }
    else
    {
        cout<<"\nData correct\n";
    }
        if(a[sum]==0)
            a[sum]=1;
        else
            a[sum]=0;
            cout<<"\nFinal codeword\n";
        for(int i=0;i<n+r;i++)
        {
            cout<<a[i];
        }*/

}
