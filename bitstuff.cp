#include<iostream>
#include<string>
using namespace std;
int main()
{
string s,flag="01111110";
char bit;
int count=0,x,i;
cout<<"Enter data\n";
while(cin>>bit&&(bit=='0'||bit=='1'))
{
    s=s+bit;
}
cout<<"Your data is\n";
cout<<s<<"\n";
for(i=0;s[i]!='\0';i++)
{
    if(s[i]=='0')
    {
        x=i+1;
        count=0;
        while(count!=5&&s[x]=='1')
        {
            count++;
            x++;
        }
            if(count==5)
            {
                s.insert(x,"0");
                i=++x;

            }
        }
}
cout<<"After stuffing\n";
cout<<flag<<" "<<s<<" "<<flag<<"\n";
for(i=0;s[i]!='\0';i++)
{
    if(s[i]=='0')
    {
        x=i+1;
        count=0;
        while(count!=5&&s[x]=='1')
        {
            count++;
            x++;
        }
            if(count==5)
            {
                s.erase(x,1);
                i=++x;

            }
        }
}
cout<<"After destuffing\n";
cout<<s;
    return 0;
}
