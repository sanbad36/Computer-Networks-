
#Name:Sanket Badjate
#Roll No:6
#Assignment No:11

import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.bind(('localhost',23000))

sock.listen(1)

clisock, (ip,port) = sock.accept()

while True:    	
	data = clisock.recv(16)

	if "stop." in data:
		break
	else:			
		print "client: " + data
	
	data = raw_input("you: ")
	clisock.send(data)
	if "stop." in data:
		break
sock.close()
            
#
#sanket@dell:~/Desktop/CN ASSIgn/A11(peer^multiuser-_TCP)(python)/tcp peer 2 peer$ python pptcpserv.py
#client: hi from client
#you: hi how are you?
#client: hi sanket
#you: 

#
