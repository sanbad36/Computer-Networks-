/*
Name:Sanket Badjate
Roll No:6
Assignment No:11
*/
import java.io.*;
import java.net.*;
public class cli
{
	public static void main(String argv[]) throws Exception {
	String sentence;
	String modifiedSentence;
 	BufferedReader inFromUser =new BufferedReader(new InputStreamReader(System.in));
 	Socket clientSocket = new Socket("10.65.6.159", 6789);
 	while (true)
	{
 		DataOutputStream outToServer =new DataOutputStream(clientSocket.getOutputStream());
 		BufferedReader inFromServer =new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
 		sentence = inFromUser.readLine();
 		outToServer.writeBytes(sentence + '\n');
 		if (sentence.equals("EXIT")) {
		break;
 		}
		modifiedSentence = inFromServer.readLine();
 		System.out.println("FROM SERVER: " + modifiedSentence);
 	}
	clientSocket.close();
 	}
 }
 /*
OUTPUT
ubuntu@linux19:~$ javac multserver.java
ubuntu@linux19:~$ java multserver
client : hi
hello
client : hi
hello prachi
client : hey
wassup
client : hey teju

**********Client1*****************
linux-23@linux23:~$ javac multclient.java
linux-23@linux23:~$ java multclient
hi
FROM SERVER: hello

***********Client2**************
linux-07@linux07:~$ javac multclient.java
linux-07@linux07:~$ java multclient
hi
FROM SERVER: hello prachi
hey teju
*/
