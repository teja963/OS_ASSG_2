# Problem Statement
  <pre>
       Create a simple device driver (character device) for the compiled kernel (in Assignment-1) and
  test it with a sample application.
  </pre>
# EXECUTION OF CHARACTER DEVICE DRIVER
  <pre>
  1) ebbchar.c 

       This C file contains the code of a CHARACTER DEVICE DRIVER.

       Character device drivers normally perform I/O in a byte stream. Examples of devices using character drivers include tape 
       drives and serial ports. Character device drivers can also provide additional interfaces not present in block drivers, 
       such as I/O control (ioctl) commands, memory mapping, and device polling.

  2) testebbchar.c

       This C file contains the code for verification of the driver whether it is running or not and also for checking the functionality of the driver.
  </pre>
# MAKEFILE
   <pre>
   1) Makefile

       This is the makefile for our character device driver. This is responsible for building objects, it is our present working 
       directory. Our main objective is to make a kbuild makefile so our makefile code contain a single line command i.e 

       obj -m := ex08_simple_char_drv.o

       make -C /lib/modules/$(uname -r)/build M=$PWD modules


       This tells there is a object in the directory named ebbchar.o and obj-m tells that this object should be built as a 
      module
   </pre>

# COMMANDS THAT ARE FOLLOWED 

* Makesure that the terminal is in the correct directory where the source code and makefile are present.

* To compile the modules of driver run
  
  		make
  
* To insert our compiled module to the kernel run
  
  		sudo insmod ebbchar.ko
  
* To verify wheteher module inserted or not run
  
  		lsmod |grep ebb
  
* To show list of character devices and block devices run
  	
  		cat /proc/devices
  
* To make the device accessible run
  
  		sudo mknod -m 666 /dev/ebbchar c 240 0 
        
* To verify whether ebbchar is available for the given node run
  
   		ls -l /dev/ebbchar
   
* To show the system log console run 
  
  		dmesg
    
* Now in the terminal compile the test.c file using
  
  		gcc testbbchar.c -o testebbchar
   
* Now run
  
		sudo ./test
  
