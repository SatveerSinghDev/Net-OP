#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

using namespace std;
int main()
{
int m,c[30],d,r=0,d1;
cout<<"Enter the no of data bits you want to enter:";
cin>>m;

while(m+r+1>pow(2,r))
{
	r++;
}

cout<<"\nNo of data bits to be added "<<r;
cout<<"\nTotal bits: "<<m+r<<endl;

cout<<"Enter the data bits: "<<endl;
for(int i=1;i<=m;i++)
  cin>>c[i];

cout<<"\nData bits entered: ";
for(int i=1;i<=m;i++)
{
	cout<<c[i]<<" ";
}

cout<<endl;


int data[m+r];
d=0;
d1=1;

for(int i=1;i<=m+r;i++)
{
	if((i)==pow(2,d))     //finding redundant bit positions
	 {
		 data[i]=0;                    //redundant bits indexes
		 d++;
	  }
	else
	 {
		 data[i]=c[d1];           //filling data to the rest positions
		 d1++;
	 }
}

cout<<"\nData bits are encoded with parity bit(0): ";
for(int i=1;i<=m+r;i++)
  cout<<data[i]<<" ";

d1=0;
int min,max=0,parity,s,j;

//Parity Bit Calculation

for(int i=1;i<=m+r;i=pow(2,d1))
 {
	  d1++;
	  parity=0;
	  //j=i;
	 // s=i;
	  min=1;     //start from 0th index everytime to count no of ones
	  max=i;
	  for(j=i;j<=m+r;)
	 {
		   for(s=j;max>=min && s<=m+r;min++,s++)
		    {
				if(data[s]==1)
				  parity++;
			}
		j=s+i;
		min=1;
	 }

if(parity%2==0)
{
	data[i]=0;
}
else
{
	data[i]=1;
}
}

cout<<endl;
cout<<"Hamming codeword bits for even parity are :";
for(int i=1;i<=m+r;i++)
  cout<<data[i]<<" ";

cout<<endl;
}
