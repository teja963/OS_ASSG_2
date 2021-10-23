# Problem Statement
	Create a simple device driver (character device) for the compiled kernel (in Assignment-1) and
	test it with a sample application.

# EXECUTION OF CHARACTER DEVICE DRIVER
  1) ebbchar.c 

	This C file contains the code of a CHARACTER DEVICE DRIVER.

	Character device drivers normally perform I/O in a byte stream. Examples of devices using character drivers include tape 
	drives and serial ports. Character device drivers can also provide additional interfaces not present in block drivers, 
	such as I/O control (ioctl) commands, memory mapping, and device polling.

  2) testebbchar.c

	This C file contains the code for verification of the driver whether it is running or not and also for checking the functionality of the driver.

# MAKEFILE

	1) Makefile

	This is the makefile for our character device driver. This is responsible for building objects, it is our present working 
	directory. Our main objective is to make a kbuild makefile so our makefile code contain a single line command i.e 

	obj -m := ex08_simple_char_drv.o

        make -C /lib/modules/$(uname -r)/build M=$PWD modules


	This tells there is a object in the directory named ebbchar.o and obj-m tells that this object should be built as a 
	module
	

# COMMANDS THAT ARE FOLLOWED 

* Makesure that the terminal is in the correct directory where the source code and makefile are present.

* To compile the modules of driver run
  <pre>
  make
  </pre>
  
* To insert our compiled module to the kernel run
  <pre>
  sudo insmod ebbchar.ko
  </pre>
  
* To verify wheteher module inserted or not run
  <pre>
  lsmod |grep ebb
  </pre>

* To show list of character devices and block devices run
  <pre>	
  cat /proc/devices
  </pre>
  
* To make the device accessible run
  <pre>	
  sudo mknod -m 666 /dev/ebbchar c 240 0 
  </pre>      
  
* To verify whether ebbchar is available for the given node run
  <pre>
   ls -l /dev/ebbchar
  </pre> 
* To show the system log console run 
  <pre>
  dmesg
  </pre>  

* Now in the terminal compile the test.c file using
  <pre>
  gcc testbbchar.c -o testebbchar
   </pre>
* Now run
  <pre> 
         command: sudo ./test
  </pre>
