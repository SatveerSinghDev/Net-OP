# include <iostream>
# include <conio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
using namespace std;
  int fr_send_at_instance;
  int arr[8];
  int arr1[8];
  int sw=0;
  int rw=0; // tells expected frame
  void input();
  void sender(int);
  void reciever(int);
void input()
{
 int n;  // no of bits for the frame
 int m;  // no of frames from n bits
 cout << "Enter the no of bits for the sequence no ";
 cin >> n;
 m = pow (2 , n);
 fr_send_at_instance = (m / 2);
 for (int i = 0 ; i < 8 ; i++)
 {
  arr[i] = i;
 }
 sender(m);
}
void sender(int m)
{
 int j = 0;
 for (int i = sw ; i < sw + fr_send_at_instance ; i++)
 {
  arr1[j] = arr[i];
  j++;
 }
 for (int i = 0 ; i < j ; i++)
  cout << " SENDER   : Frame " << arr1[i] << " is sent\n";
 reciever (m);
}
void reciever(int m)
{
 time_t t;
 int f;
 int f1;
 int a1;
 char ch;
 srand((unsigned) time(&t));
 f = rand() % 10;
   // if = 5 frame is discarded for some reason
   // else they are correctly recieved
if (f != 5)
 {
  for (int i = 0 ; i < fr_send_at_instance ; i++)
  {
   if (rw == arr1[i])
   {
    cout << "RECIEVER : Frame " << arr1[i] << " recieved correctly\n";
    rw = (rw + 1) % m;
   }
   else
    cout << "RECIEVER : Duplicate frame " << arr1[i] << " discarded\n";
  }
 }
 else
 {
  f1 = rand() % fr_send_at_instance;   // f1 gives index of the frame being lost
  for (int i = 0 ; i < f1 ; i++)
  {
   if (rw == arr1[i])
   {
    cout << " RECIEVER : Frame " << arr1[i] << " recieved correctly\n";
    rw = (rw + 1) % m;
   }
   else
    cout << " RECIEVER : Duplicate frame " << arr1[i] << " discarded\n";
  }
  for (int i = f1 + 1 ; i < fr_send_at_instance ; i++)
    cout << " RECIEVER : Frame " << arr1[i] << " discarded\n";
  cout << " (SENDER TIMEOUTS --> RESEND THE FRAME)\n";
  sw = arr1[f1];
 }
 cout << "Want to continue...";
 cin >> ch;
 if (ch == 'y')
  sender(m);
 else
  exit(0);
}
int main()
{
 input();
}
