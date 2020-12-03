/*
Name:Sanket Badjate
Roll No:6
Assignment No:4
*/
import java.lang.System;
import java.net.*;
import java.io.*;
import java.util.*;

public class goc {
	static Socket s;

	public static void main(String a[]) throws SocketException {
		try {
			int v[] = new int[8];
			int n = 0;
			int i;
			//InetAddress addr = InetAddress.getByName("Localhost");		//get the ip address
			//System.out.println(addr);
			s = new Socket("localhost",9999);
			DataOutputStream dos = new DataOutputStream(s.getOutputStream());
			DataInputStream dis = new DataInputStream(s.getInputStream());
			int p = dis.read();
			System.out.println("No of frame is:" + p);



		Scanner scan=new Scanner(System.in);
		System.out.println("Enter packet no. to generate error: ");
		int perr=scan.nextInt();






				//recieving frames
			for ( i = 0; i < p; i++) {
				v[i] = dis.read();
			}


	v[perr] = -1;	//generate error manually at perr location


			for ( i = 0; i < p; i++)
			 {
					System.out.println("Received frame no. "+i+" :" + v[i]);
					Thread.sleep(500);
			}


	System.out.println("\n------------------------------------------\nRequesting packets from packet no."+perr);


				 for(i=0;i<p;i++){
				 	if(v[i]==-1)
				 		dos.write(i);
				}




//retransmission
		for(i=0;i<p;i++)
		{
			if(v[i]==-1)
			{
				int m=i;

				for(m=i;m<p;m++)
				{
					Thread.sleep(2000);
					System.out.println("\nRequest to retransmit from packet no "+m+" again!");
					n = m;
					v[n]=dis.read();
					System.out.println("Received frame is: " + v[n]);
				}
				continue;
			}
			continue;
		}
				System.out.println("------------------------------------------\n");
				Thread.sleep(500);
				for(i = 0; i < perr; i++)
			 	{
					System.out.println("OLD Packet no.: "+i+" :" + v[i]);
				}
				System.out.println();
				for(i=perr;i<p;i++)
				{
					System.out.println("NEW Packet no.: "+i+" :" + v[i]);
				}



			System.out.println("\nAll frame recieved successfully\n");


		} catch (Exception e) {
			System.out.println(e);
		}

	}
}
/*OUTPUT
linux-15@linux15:~/GroupA/Ass4$ javac goc.java
linux-15@linux15:~/GroupA/Ass4$ java goc
No of frame is:8
Enter packet no. to generate error:
2
Received frame no. 0 :30
Received frame no. 1 :40
Received frame no. 2 :-1
Received frame no. 3 :60
Received frame no. 4 :70
Received frame no. 5 :80
Received frame no. 6 :90
Received frame no. 7 :100

------------------------------------------
Requesting packets from packet no.2

Request to retransmit from packet no 2 again!
Received frame is: 50

Request to retransmit from packet no 3 again!
Received frame is: 60

Request to retransmit from packet no 4 again!
Received frame is: 70

Request to retransmit from packet no 5 again!
Received frame is: 80

Request to retransmit from packet no 6 again!
Received frame is: 90

Request to retransmit from packet no 7 again!
Received frame is: 100
------------------------------------------

OLD Packet no.: 0 :30
OLD Packet no.: 1 :40

NEW Packet no.: 2 :50
NEW Packet no.: 3 :60
NEW Packet no.: 4 :70
NEW Packet no.: 5 :80
NEW Packet no.: 6 :90
NEW Packet no.: 7 :100

All frame recieved successfully
*/
