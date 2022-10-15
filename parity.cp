#include<iostream>
#include<string.h>
using namespace std;

string str,str1,str2;
int l,l1;

void input()
{
	
	char bit;
	cout<<"enter the string=";
	while(cin>>bit &&(bit=='0' || bit=='1'))
	{
		str+=bit;
		
	}
	
	cout<<"\nthe string entered is="<<str;
	
}		

void sender_side()
{  
  
  int l;
  l=str.size();
  char parity;
  parity=str[0];
  
  for(int i=1;i<l;i++)
  {
	  parity=parity^str[i];
	  
   }
   str1=str+parity;
   cout<<"\nthe parity of the string input is="<<parity;
   cout<<"\nstring after appending parity bit="<<str1;
   
   
}  

void receiver_side()
{
	
	int l1;
	l1=str1.size();
	
	cout<<"\nenter the position whose bit shall be appended=";
	int bitpos;
	cin>>bitpos;
	int errorbit;
	cout<<"\nenter the error bit=";
	cin>>errorbit;
	for(int i=0;i<l1;i++)
	{
		
		if(i==bitpos)
		{
			str2[bitpos]=errorbit;
		}
		else
		str2[i]=str1[i];
		
	}		
	cout<<"\nthe string with error is="<<str2		;
	char par;
	par=str2[0];
	
	for(int i=1;i<l1;i++)
	{
		par=par^str2[i];
		
	}
	
	if(par==0)
	{
		cout<<"\nthere is no error in the data";
		
	}
	
	else
	{
		cout<<"\nthere is an error in the data";
		
	}
	

 
}

int main()
{
	input();
	sender_side();
	receiver_side();
	
}	 				
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 	  
