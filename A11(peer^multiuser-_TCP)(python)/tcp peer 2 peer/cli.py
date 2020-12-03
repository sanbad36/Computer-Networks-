
#Name:Sanket Badjate
#Roll No:6
#Assignment No:11

import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.connect(('127.0.0.1',23000))

sock.send("hi from client")

while True:
	
	data = sock.recv(16)
	if "stop." in data:
		break
	else:			
		print "server: " + data

	data = raw_input("you: ")
	sock.send(data)
	if "stop." in data:
		break
sock.close()



#sanket@dell:~/Desktop/CN ASSIgn/A11(peer^multiuser-_TCP)(python)/tcp peer 2 peer$ python pptcpcli.py
#hi sanket
#server: hi how are you?
#you: 


