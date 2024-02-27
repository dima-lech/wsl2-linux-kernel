obj-m += kernel-module-test.o 
 
PWD := $(CURDIR)
KERNEL_DIR := ../WSL2-Linux-Kernel-linux-msft-wsl-5.15.146.1 
 
all: 
	make -C $(KERNEL_DIR) M=$(shell pwd) modules
 
clean: 
	make -C $(KERNEL_DIR) M=$(shell pwd) clean

install: 
	sudo insmod kernel-module-test.ko

uninstall:
	sudo rmmod kernel_module_test


