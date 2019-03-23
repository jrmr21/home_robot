#********************* MakeFile ****************

	# to choise your config plus your card on the computer
	# and use a command "mbed detect"
		

TARGET = target/stm32f1x.cfg			# select your target setting in source file of openocd

#INTERFACE = interface/stlink.cfg		# select in source file of openocd
						# here: https://github.com/ntfreak/openocd/tree/master/tcl	
INTERFACE = interface/stlink-v2.cfg

NAME = ft_MbedOs					# your project name (actual folder)

FOLDER = BUILD/NUCLEO_F103RB/GCC_ARM/		# your destination build
						# set your config with: "mbed target NUCLEO_F103RB" (for example)


all : 
	mbed compile				# set your compilator: "mbed toolchain GCC_ARM" (for example)
						# go to edit :x
						#
upload_off :
	sudo openocd -f $(INTERFACE) -f $(TARGET) \
	-c " init " \
	-c " reset init " \
	-c " halt " \
	-c "program mbed_off.bin reset exit 0x08000000"

upload : 
	sudo openocd -f $(INTERFACE)  -f $(TARGET) \
	-c " init " \
	-c " reset init " \
	-c " halt " \
	-c " program BUILD/NUCLEO_F103RB/GCC_ARM/ft_MbedOs.bin reset exit 0x08000000"

clean :
	rm -f $(FOLDER)*.o \
	rm -f $(FOLDER)$(NAME).helf \
	rm -f $(FOLDER)$(NAME).bin \
	rm -f $(FOLDER)$(NAME).elf

	

	# to send command to the card with openocd use: "sudo openocd -f target/stm32f1x.cfg -f interface/stlink.cfg"
	# and in other terminal "telnet localhost 4444" 
