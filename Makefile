obj -m := assgn2_simple_char_drv.o

all:
   make -C /lib/modules/$(uname -r)/build M=$PWD modules

clean:
   make -C /lib/modules/$(uname -r)/build M=$PWD clean

