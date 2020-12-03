
#Name:Sanket Badjate
#Roll No:6
#Assignment No:12

import socket
port = 23000
ip = ''

clisock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

clisock.sendto("hello from client", (ip, port))
print clisock.recv(100)
clisock.close()
#sanket@dell:~/Desktop/CN ASSIgn/A12(peer^multiuser-_UDP)(python)/MultiChat$ python cliu.py
#hello from client

