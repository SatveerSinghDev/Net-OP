#include<iostream>
#include<unistd.h>
#include<time.h>
#include<windows.h>   // include this if working on WINDOWS.
using namespace std;
int frame[4];
unsigned long begTime;

void wait_for_event()
{

    Sleep(9997);        // use capital S in sleep if working in windows and argument in milli second
}


void getdata()
{

   cout<<"enter the frame of size 4=";
    for(int i=0;i<4;i++)
    {
        cin>>frame[i];
    }
    begTime=clock(); //start timer, copy current clock's value in begTime.
}

void send_frame()
{
  cout<<"Sender:  frame has been sent"<<endl;
}
void send_acknowledgement()
{
    cout<<"Receiver:  acknowledgement has been sent";
    cout<<endl;
}

void receive_acknowledgement()
{
    cout<<"Sender:  acknowledgement has been received";
    cout<<endl;
}

void receive_frame()
{
    int receivedframe[4];
    bool flag=false;
    for(int i=0;i<4;i++)
    {
      receivedframe[i]=frame[i];
    }
    for(int i=0;i<4;i++)
    {
       if(receivedframe[i]==frame[i])
            flag=true;

    }
    if(flag==true)
     {
         cout<<"Receiver:  frame received"<<endl;
         flag=false;   //Edit:If frame is received then set flag again to false for next frame.
      }

}
int main()
{
   bool cansend=true;
   int n;

     cout<<"enter the number of frames";
     cin>>n;

     for(int i=0;(i<n);i++){
		 if(!(cansend)){
		   cout<<"timeout occurred, sending frame again."<<endl;   //if cansend is false then timeout occurrs and frame is resent.
            cansend=true;      //cansend becomes true again.
            begTime=clock();      //reset the timer to current clock time and start the timer clock.
           }
         else
			 getdata();             //take next data if timeout does not occur.

          send_frame();
          receive_frame();
          send_acknowledgement();
          wait_for_event();
          cout<<"["<<difftime(clock(),begTime)<<"]"<<endl;

          if(difftime(clock(),begTime)>10000)    //if in given time 10000ms ack is not received then timeout occurs.(for windows the timer value is in millisecond, use 10000 or as appropriate).
           {
			   cansend=false;
		         i--;  // for loop will run one more time for the resent frame. so i--.
           }
         else
           receive_acknowledgement();    //else ack is received.
            cout<<endl;
         }


}
