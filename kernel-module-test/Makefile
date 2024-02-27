obj-m += kernel-module-test.o 
 
PWD := $(CURDIR)
KERNEL_DIR := /lib/modules/`uname -r`/build
 
all: 
	make -C $(KERNEL_DIR) M=$(shell pwd) modules
 
clean: 
	make -C $(KERNEL_DIR) M=$(shell pwd) clean

install: 
	sudo insmod kernel-module-test.ko

uninstall:
	sudo rmmod kernel_module_test


