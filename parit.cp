#include<iostream>
#include<stdlib.h>
using namespace std;
class parit
{
public:
    string s,s2;
    char paritys,parityr,bit;
    int i,c,l;
void sender()
{
    cout<<"enter bits\n";
    while(cin>>bit&&(bit=='0'||bit=='1'))
{
    s=s+bit;
}
cout<<"You data is\n";
cout<<s<<endl;
paritys=s[0];
for(i=1;s[i]!='\0';i++)
{
    if(paritys==s[i])
        paritys='0';
    else
        paritys='1';

}
cout<<"\nParity is="<<paritys<<endl;
s2=s+paritys;
cout<<"Data after parity\n";
cout<<s2<<endl;
}


void receiver()
{
int l=s2.length();
cout<<"enter 1 for parity bit check without error\n";
cout<<"enter 2 for parity bit check with error\n";
int c;
cout<<"enter your choice";
cin>>c;
switch(c)
{
case 1:
    {

        parityr=s2[0];
     for(i=1;i<l-1;i++)
     {
    if(parityr==s2[i])
        parityr='0';
    else
        parityr='1';

     }
   cout<<"\nParity of receiver side is="<<parityr<<endl;
   if(paritys==parityr)
    cout<<"Data is correct\n";
    else
    cout<<"Data is corrupted";
    break;
    }
case 2:
    {
        char chh;
int pos;int error;int k;string s3;
cout<<"enter the position\n";
cin>>pos;
cout<<"enter the error bit(1/0)\n";
cin>>error;
for(int j=0;j<l;j++)
{
    if(j==pos)
    {
        s2[j]=error;
    }
    else
    {
        s2[j]=s2[j];
    }
}
cout<<"Data is"<<" "<<s3<<endl;
parityr=s3[0];
     for(i=1;i<l-1;i++)
     {
    if(parityr==s3[i])
        parityr='0';
    else
        parityr='1';

     }
   cout<<"\nParity of receiver side is="<<parityr<<endl;
   if(paritys==parityr)
    cout<<"Data is correct\n";
    else
    cout<<"Data is corrupted";
     break;
    }
}
}
};

 int main()
 {

     parit ob;
     ob.sender();
     ob.receiver();
     return 0;
 }
