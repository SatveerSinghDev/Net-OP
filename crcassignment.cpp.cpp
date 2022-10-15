#include<iostream>
#include<stdlib.h>
using namespace std;
class cyclic
{
   public:
        void sender();
        void receiver(int m,int n,int z,int frame[],int gen[],int div[],int temp[]);
        int k,m,n,z;
        int div[];
        int frame[];
        int temp[];
        int gen[];
};
    void cyclic::sender()
	{

	    int m,n,z;
        cout<<"enter the size of the generator\n";
        cin>>n;
        int div[n];int gen[n];
        cout<<"enter the data\n";
        for(int i=0;i<n;i++)
        {
            cin>>gen[i];
        }
        cout<<"enter the size of the frame\n";
        cin>>m;
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
        z=n-1;int l=0;
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
        if(temp[0]==1)
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
        for(int i=0;i<m-1;i++)
        {
            k=0;
            if(div[i+1]==1)
            {
                div[n+i]=temp[n+i];
                for(int j=1;j<=n;j++)
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
                for(int j=1;j<=n;j++)
                {
                    div[j+i]=div[j+i];
                }
            }
        }
        cout<<"the remainder is\n";
        for(int i=m;i<m+z;i++)
        {
            cout<<div[i];
        }
        for(int i=m;i<m+z;i++)
        {
            frame[i]=div[i];
        }
        cout<<"\ndata sent is\n";
        for(int i=0;i<m+z;i++)
        {
            cout<<frame[i];
        }
        cout<<"\nEnter 1 to generate no error\n";
        cout<<"Enter 2 to generate an error\n";
        cout<<"Enter your choice\n";
        int c;
        cin>>c;
        switch(c)
        {
            case 1:
                {
                    cout<<"without error\n";
                    for(int i=0;i<m+z;i++)
                    {
                        cout<<frame[i];
                    }
                    receiver(m,n,z,frame,gen,div,temp);
                    break;
                }
            case 2:
                {
                    int pos,error;
                    cout<<"\nenter the position at which you want to change the bit\n";
                    cin>>pos;
                    cout<<"enter the error bit\n";
                    cin>>error;
                    for(int j=0;j<m+z;j++)
                    {
                        if(j==pos)
                        {
                            frame[j]=error;
                        }
                        else
                        {
                            frame[j]=frame[j];
                        }
                    }
                    cout<<"\nError generate\n";
                    for(int i=0;i<m+z;i++)
                    {
                        cout<<frame[i];
                    }
                    receiver(m,n,z,frame,gen,div,temp);
                }
                break;
            }
	}
    void cyclic::receiver(int m,int n,int z,int frame[],int gen[],int div[],int temp[])
	{
        cout<<"\nReceiver side\n";
        if(frame[0]==1)
        {
            for(int i=0;i<n;i++)
            {
                if(frame[i]==gen[i])
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
                div[i]=frame[i];
            }
        }
        for(int i=0;i<m-1;i++)
        {
            k=0;
            if(div[i+1]==1)
            {
                div[n+i]=frame[n+i];
                for(int j=1;j<=n;j++)
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
                div[n+i]=frame[n+i];
                for(int j=1;j<=n;j++)
                {
                    div[j+i]=div[j+i];
                }
            }
        }
        bool flag;
        cout<<"the remainder is\n";
        for(int i=m;i<m+z;i++)
        {
            cout<<div[i];
            if(div[i]==0)
                flag=true;
            else
                flag=false;
        }
        if(flag==true)
            cout<<"\nDATA IS CORRECT\n";
        else
            cout<<"\nDATA IS CORRUPTED\n";
        }

	int main()
    {
        cyclic ob;
        ob.sender();
        return 0;
    }




