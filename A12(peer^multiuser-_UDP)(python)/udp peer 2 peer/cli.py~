
#Name:Sanket Badjate
#Roll No:6
#Assignment No:12

import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.sendto("Hi from client", ('localhost', 10000))
while True:    	
	msg, (ip, port) = sock.recvfrom(100)

	if "stop." in msg:
		break
	else:			
		print "server: " + msg
	
	msg = raw_input("you: ")
	sock.sendto(msg, (ip,port))
	if "stop." in msg:
		break
sock.close()
#OUTPUT
#admin1@ccl17:~$ python pptcpserv.py
#client: hi from client
#you: hi
#client: how r u
#you: 


#admin1@ccl17:~$ python pptcpcli.py
#server: hi
#you: how r u
#i am fine


