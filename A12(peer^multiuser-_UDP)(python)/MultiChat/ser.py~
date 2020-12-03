
#Name:Sanket Badjate
#Roll No:6
#Assignment No:12

import socket

servsock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

servsock.bind(('', 23000))


while 1:
		msg, (ip, port) = servsock.recvfrom(100)
		#print "client connected to ip: " + ip + " and port: " + str(port)
		print "received message: " + msg
		servsock.sendto(msg, (ip,port))




#sanket@dell:~/Desktop/CN ASSIgn/A12(peer^multiuser-_UDP)(python)/MultiChat$ python servu.py
#received message: hello from client

