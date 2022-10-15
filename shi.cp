#include<iostream>
#include<sstream>
#include<string>
#include<bitset>
using namespace std;
int dectobin(int n)
{
    int i=1;int r,bin=0,m=n;
    while(n>0)
    {
        r=n%2;
        bin=bin+(r*i);
        n=n/2;

        i=i*10;
    }
    return bin;
}

int main()
{
    string s,str;int b1,b2,b3,b4,count=0;
    char t;int res,res2,res3,res4;
    string result1,result2,result3,result4;
    cout<<"Enter the decimal dotted IPv4 address";
    cin>>s;
    s.append(".");
     for(int i=0;i<s.length();i++)
  {

      if(s[i]!='.')
      {

          t=s[i];
          str+=t;
      }
      else
      {
          count++;

          if(count==1)
          {
          b1=stoi(str);
          res=dectobin(b1);
          result1=to_string(res);
          }
          else if(count==2)
          {
           b2=stoi(str);
           res2=dectobin(b2);
           result2=to_string(res2);
          }
          else if(count==3)
          {
              b3=stoi(str);
              res3=dectobin(b3);
              result3=to_string(res3);

          }
          else if(count==4)
          {
            b4=stoi(str);
            res4=dectobin(b4);
            result4=to_string(res4);
          }
          str.erase();

      }
}
result1.append(".");
result1.append(result2).append(".").append(result3).append(".").append(result4);
cout<<result1;
}
