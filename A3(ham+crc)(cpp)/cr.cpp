/*
Name:Sanket Badjate
Roll No:6
Assignment No:3
*/
#include <iostream>
using namespace std;
int main()
{
int i,j,k,l;
	int m;
	cout<<"\n Enter message size: ";
	cin>>m;
	
	int msg[20];
	
	cout<<"\n Enter message:";
	for(i=0;i<m;i++)
	{
		cin>>msg[i];
	}
	int g;
	cout<<"\n Enter Generator size: ";
	cin>>g;
	
	int gen[20];
	
	cout<<"\n Enter Generator:";
	for(i=0;i<g;i++)
	{
		cin>>gen[i];
	}

	cout<<"\n Sender Side:";
	cout<<"\n message: ";
	for(i=0;i<m;i++)
	{
		cout<<msg[i];
	}
	cout<<"\n Generator :";
	for(i=0;i<g;i++)
	{
		cout<<gen[i];
	}

	int zero=g-1;
	cout<<"\n Number of 0's to be appended: "<<zero;
	for (i=m;i<m+zero;i++)
	{
		msg[i]=0;
	}

	int temp[20];
	for(i=0;i<20;i++)
	{
		temp[i]=msg[i];
	}

	cout<<"\n Message after appending 0's :";
	for(i=0; i<m+g;i++)
	{
		cout<<temp[i];
	}
	for(i=0;i<m;i++)
	{
		j=0;
		k=i;
		if (temp[k]>=gen[j])
		{
			for(j=0,k=i;j<g;j++,k++)
			{
				if((temp[k]==1 && gen[j]==1) || (temp[k]==0 && gen[j]==0))
				{
					temp[k]=0;
				}
				else
				{
					temp[k]=1;
				}
			}
		}
	}

	int crc[15];
	for(i=0,j=m;i<zero;i++,j++)
	{
		crc[i]=temp[j];
	}

	cout<<"\n CRC bits: ";
	for(i=0;i<zero;i++)
	{
		cout<<crc[i];
	}

	cout<<"\n Transmitted Frame: ";
	int tf[15];
	for(i=0;i<m;i++)
	{
		tf[i]=msg[i];
	}
	for(i=m,j=0;i<m+zero;i++,j++)
	{
		tf[i]=crc[j];
	}
	for(i=0;i<m+zero;i++)
	{
		cout<<tf[i];
	}

	cout<<"\n Receiver side : ";
	cout<<"\n Received Frame: ";

	for(i=0;i<m+zero;i++)
	{
		cout<<tf[i];
	}

	for(i=0;i<m+zero;i++)
	{
		temp[i]=tf[i];
	}
	for(i=0;i<m+zero;i++)
	{
		j=0;
		k=i;
		if (temp[k]>=gen[j])
		{
			for(j=0,k=i;j<g;j++,k++)
			{
				if((temp[k]==1 && gen[j]==1) || (temp[k]==0 && gen[j]==0))
				{
					temp[k]=0;
				}
				else
				{
					temp[k]=1;
				}
			}
		}
	}

	cout<<"\n Reaminder: ";
	int rrem[15];
	for (i=m,j=0;i<m+zero;i++,j++)
	{
		rrem[j]= temp[i];
	}
	for(i=0;i<zero;i++)
	{
		cout<<rrem[i];
	}

	int flag=0;
	for(i=0;i<zero;i++)
	{
		if(rrem[i]!=0)
		{
			flag=1;
		}
	}

	if(flag==0)
	{
		cout<<"\n Since Remainder Is 0 Hence Message Transmitted From Sender To Receriver Is Correct";
	}
	else
	{
		cout<<"\n Since Remainder Is Not 0 Hence Message Transmitted From Sender To Receriver Contains Error";
	}
	
}
/*
OUTPUT:
sanket@dell:~/Desktop/CN ASSIgn/A3(ham+crc)(cpp)$ g++ cr.cpp
sanket@dell:~/Desktop/CN ASSIgn/A3(ham+crc)(cpp)$ ./a.out

 Enter message size: 6

 Enter message:1
0
1
0
1
0

 Enter Generator size: 4

 Enter Generator:1
0
1
1

 Sender Side:
 message: 101010
 Generator :1011
 Number of 0's to be appended: 3
 Message after appending 0's :10101000032763
 CRC bits: 001
 Transmitted Frame: 101010001
 Receiver side : 
 Received Frame: 101010001
 Reaminder: 000
 Since Remainder Is 0 Hence Message Transmitted From Sender To Receriver Is Correct
*/
