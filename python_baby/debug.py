import serial

ser = serial.Serial('/dev/ttyUSB0')  # open serial port
ser.baudrate = 9600
msg = 0
while True:
	print ser.readline()
