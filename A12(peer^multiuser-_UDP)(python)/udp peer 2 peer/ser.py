
#Name:Sanket Badjate
#Roll No:6
#Assignment No:12

import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('localhost', 10000))

msg, (ip, port) = sock.recvfrom(100)
print "client connected to ip: " + ip + " and port: " + str(port)
print "received message: " + msg
sock.sendto("Hello from server", (ip,port))



while True:    	
	msg, (ip, port) = sock.recvfrom(100)
	print "client connected to ip: " + ip + " and port: " + str(port)
	if "stop." in msg:
		break
	else:			
		print "client: " + msg
	
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


