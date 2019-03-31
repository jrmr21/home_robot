import socket
import serial
import time

# A UDP server

# Set up a UDP server
#UDPSock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

# Listen on port 5006
# (to all IP addresses on this system)
#UDPSock.bind(("", 5006))


ser = serial.Serial('/dev/ttyUSB0')  # open serial port
ser.baudrate = 9600
#ser.open()      #opens port 
msg = 0
# Report on all data packets received and
# where they came from in each case (as this is
# UDP, each may be from a different source and it's
# up to the server to sort this out!)
while True:
#       data,addr = UDPSock.recvfrom(1024)	# size
               #trop d info ( ip +port +msg )print data.strip(),addr
#       msg = data.strip()
        msg = "x150"
	
#	if msg == "x" :
#		print "axe X: "
#		msg = msg [:1]
#	elif msg == "y" :
#		print "axe Y: "
#		msg = msg[:1]
		
#	print(msg)
        #ser.open()      #opens port 
	ser.write(b'y120')
	time.sleep(1)
        ser.write(b'y10')
        time.sleep(1)
	
#	if msg == "1005" :
#		UDPSock.close()
#		break;
