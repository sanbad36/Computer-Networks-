/*
Name:Sanket Badjate
Roll No:6
Assignment No:11
*/
import java.io.*;
import java.net.*;

public class ser
{
	public static void main(String argv[]) throws Exception
	{
 		ServerSocket welcomeSocket = new ServerSocket(6789);
 		Responder h = new Responder();
 // server runs for infinite time and
 // waits for clients to connect
		while (true)
		{
		Socket connectionSocket = welcomeSocket.accept();

// on connection establishment start a new thread for each client
 // each thread shares a common responder object
 // which will be used to respond every client request

 		Thread t = new Thread(new MyServer(h, connectionSocket));

// start thread
 		t.start();
		}
	}
}


class MyServer implements Runnable
{
	Responder h;
	Socket connectionSocket;
	public MyServer(Responder h, Socket connectionSocket)
	{
	this.h = h;
	this.connectionSocket = connectionSocket;
	 }

//@Override
 	public void run()
	{
 		while (h.responderMethod(connectionSocket))
		{
 			try
			{
 // once an conversation with one client done,
 // give chance to other threads
 // so make this thread sleep
 			Thread.sleep(5000);
 			} catch (InterruptedException ex) { }
 		}
 		try {
 		      connectionSocket.close();
 		    } catch (IOException ex) { }

	}
}

class Responder
{
	String serverSentence;
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

// on client process termination or
 // client sends EXIT then to return false to close connection
 // else return true to keep connection alive
 // and continue conversation
	synchronized public boolean responderMethod(Socket connectionSocket)
	{
		try {
 			BufferedReader inFromClient =new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
 			DataOutputStream outToClient =new DataOutputStream(connectionSocket.getOutputStream());
 			String clientSentence = inFromClient.readLine();

// if client process terminates it get null, so close connection
 			if (clientSentence == null || clientSentence.equals("EXIT")) {
 			return false;
			}

			if (clientSentence != null) {
 			System.out.println("client : " + clientSentence);
 			}
			serverSentence = br.readLine() + "\n";
 			outToClient.writeBytes(serverSentence);
 			return true;
 			} catch (SocketException e) {
 			System.out.println("Disconnected");
 			return false;
 			} catch (Exception e) {
 			e.printStackTrace();
 			return false;}
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
