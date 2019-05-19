obj-m += modcr0cd.o
modcr0cd-objs := cr0cd.o asm.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

