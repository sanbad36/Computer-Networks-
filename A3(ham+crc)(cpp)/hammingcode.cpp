/*
Name:Sanket Badjate
Roll No:6
Assignment No:3
*/
#include<iostream>
using namespace std;
int main()
{

 int p,i,a[7],b[7],a1,a2,a3;
 cout<<"Enter 4-bit binary number";
  cin>>a[3];
  cin>>a[5];
  cin>>a[6];
  cin>>a[7];

a[1]=a[3]^a[5]^a[7];
a[2]=a[3]^a[6]^a[7];
a[4]=a[5]^a[6]^a[7];
 
 for(i=1;i<=7;i++)
 {
  cout<<a[i];
  }
  
  cout<<"\nThe seven bits are:";
  for(i=1;i<=7;i++)
   {
  cin>>b[i]; 
   }
 a1=b[1]^b[3]^b[5]^b[7];
 a2=b[2]^b[3]^b[6]^b[7];
 a3=b[4]^b[5]^b[6]^b[7];
 p=a1*1+a2*2+a3*4;
if(p==0)
{
cout<<"Errorless bit";
}
else
{
cout<<"Error at given position\n"<<p<<endl;
}
if(b[p]==0)
{
b[p]=1;
}
else
{
 b[p]=0;
 }
 return 0;
 }
/*
sanket@dell:~/Desktop/CN ASSIgn/A3(ham+crc)(cpp)$ g++ hammingcode.cpp
sanket@dell:~/Desktop/CN ASSIgn/A3(ham+crc)(cpp)$ ./a.out
Enter 4-bit binary number1
0
1
1
0110011
The seven bits are:0
1
1
0
0
1
1
Errorless bit
*/
