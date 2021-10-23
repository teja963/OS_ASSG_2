# Problem Statement
  <pre>
       Create a simple device driver (character device) for the compiled kernel (in Assignment-1) and
  test it with a sample application.
  </pre>
# EXECUTION OF CHARACTER DEVICE DRIVER
  <pre>
  1) assgn2_simple_char_drv.c 

       This C file contains the code of a CHARACTER DEVICE DRIVER.

       Character device drivers normally perform I/O in a byte stream. Examples of devices using character drivers include tape 
       drives and serial ports. Character device drivers can also provide additional interfaces not present in block drivers, 
       such as I/O control (ioctl) commands, memory mapping, and device polling.

  </pre>
# MAKEFILE
   <pre>
   1) Makefile

       This is the makefile for our character device driver. This is responsible for building objects, it is our present working 
       directory. Our main objective is to make a kbuild makefile so our makefile code contain a single line command i.e 

      obj -m := ex07_simple_char_drv.o

    all:
      make -C /lib/modules/$(uname -r)/build M=$PWD modules

  clean:
      make -C /lib/modules/$(uname -r)/build M=$PWD clean


       This tells there is a object in the directory named ebbchar.o and obj-m tells that this object should be built as a 
      module
   </pre>

# COMMANDS THAT ARE FOLLOWED 

* Makesure that the terminal is in the correct directory where the source code and makefile are present.

* To compile the modules of driver run
  
  		make
  
* To insert our compiled module to the kernel run
  
  		sudo insmod assgn2_simple_char_drv.ko
  
* To verify wheteher module inserted or not run
  
  		lsmod |grep assgn2
  
* To show list of character devices and block devices run
  	
  		cat /proc/devices
  
* To make the device accessible run
  
  		sudo mknod -m 666 /dev/simple_char_device c 240 0 
        
* To verify whether char_device is available for the given node run
  
   		ls -l /dev/simple_char_device
   
* To show the system log console run 
  
  		sudo tail -f /var/log/syslog
    
  
