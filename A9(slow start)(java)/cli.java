/*
Name:Sanket Badjate
Roll No:6
Assignment No:9
*/
import java.io.*;

import java.net.*;

public class cli

{

	public static void main(String args[])throws IOException

	{

		try
		{
			Socket s=new Socket("127.0.0.1",9999);

			DataInputStream in=new DataInputStream(s.getInputStream());

			DataOutputStream out=new DataOutputStream(s.getOutputStream());
			DataInputStream din=new DataInputStream(System.in);
			String msg=in.readUTF();
			System.out.println(msg);
			int buffsize=Integer.parseInt(din.readLine());
			out.write(buffsize);
			out.close();

			in.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
/*OUTPUT
admin1@ccl17:~$ javac Server.java
admin1@ccl17:~$ java Server
Congestion window size is: 2
Congestion window size is: 4
Congestion window size is: 8
Congestion window size is: 16
Time out occure ack not recieve at sender side
The updated congestion window size is: 8


admin1@ccl17:~$ javac Client.java
admin1@ccl17:~$ java Client
Enter Size:
8
*/

